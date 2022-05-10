# sitk-superbuild

A simple setup demo for including SimpleITK as dependency using [SuperBuild](https://www.kitware.com/cmake-superbuilds-git-submodules/). SuperBuild is wildly used in SimpleITK, Slicer, ParaView and other Kitware products and makes dependency management more easier.

On Windows, the path of the source directory should be short enough (eg. `C:/src/sitk-superbuild/`) to ensure the build output file path is acceptable. Because Windows path limitation is 256 characters long. ITK will report error at build time when you path is too long:

```bash
ITK source code directory path length is too long (59 > 50).Please move the
       ITK source code directory to a directory with a shorter path.
```

## Pitfalls

- VSCode cannot handle IntelliSense correctly if using EP, see: https://gitlab.kitware.com/cmake/cmake/-/issues/22826 and https://github.com/microsoft/vscode-cpptools/discussions/8248, I suggest add the include paths manually to your `.vscode/c_cpp_properties.json` file.

## References

- https://github.com/dev-cafe/cmake-cookbook/blob/master/chapter-08/recipe-01/README.md
- https://cmake.org/cmake/help/latest/module/ExternalProject.html
- https://www.zhihu.com/column/c_1490802622991306752
- https://www.kitware.com/cmake-superbuilds-git-submodules/
