#include <SimpleITK.h>
#include <sitkImageOperators.h>

#include "lib.h"
namespace sitk = itk::simple;

int argc;
char** argv;

int test_sitk_write() {
    // create convenient namespace alias
    namespace sitk = itk::simple;

    sitk::PixelIDValueEnum pixelType = sitk::sitkUInt8;
    std::vector<unsigned int> imageSize(2, 128);

    // Create a black image
    sitk::Image image(imageSize, pixelType);

    // Add a Gaussian blob to the image
    std::vector<double> blobSize(2, 64.0);
    std::vector<double> blobCenter(2, 64.0);
    image = image + sitk::GaussianSource(pixelType, imageSize, blobSize, blobCenter);

    // Write the image as a PNG file
    sitk::WriteImage(image, "blob.local.png");

    return 0;
}

int test_sitk_read_dcm() {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " sitk_dcm <dcm_folder>" << std::endl;
        return 0;
    }
    const std::string inputDirectory = argv[2];

    // Read the Dicom image series
    sitk::ImageSeriesReader reader;
    const std::vector<std::string> dicom_names = sitk::ImageSeriesReader::GetGDCMSeriesFileNames(inputDirectory);
    std::cout << "dicom_names.size():" << dicom_names.size() << std::endl;
    std::cout << "dicom_names[0]:" << dicom_names[0] << std::endl;
    reader.SetFileNames(dicom_names);

    sitk::Image image = reader.Execute();
    std::vector<unsigned int> size = image.GetSize();
    std::cout << "Image size: " << size[0] << " " << size[1] << " " << size[2] << std::endl;
    auto spacing = image.GetSpacing();
    std::cout << "Image spacing: " << spacing[0] << " " << spacing[1] << " " << spacing[2] << std::endl;
    std::cout << "Image num of componets: " << image.GetNumberOfComponentsPerPixel() << std::endl;

    /*
    Output:
    dicom_names.size():510
    dicom_names[0]: .../.../xxx.dcm
    Image size: 512 512 510
    Image spacing: 0.3 0.3 0.3
    */

    return 0;
}

int main(int argc_main, char* argv_main[]) {
    test();
    argc = argc_main;
    argv = argv_main;
    if (argc >= 2) {
        auto type = std::string(argv[1]);
        if (type == "sitk_write") {
            return test_sitk_write();
        } else if (type == "sitk_dcm") {
            return test_sitk_read_dcm();
        }
    }
    std::cout << "Usage: " << argv[0] << " [sitk_write|sitk_dcm|]" << std::endl;

    return 0;
}
