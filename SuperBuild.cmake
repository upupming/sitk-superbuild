include(ExternalProject)

file(GLOB external_project_cmake_files "SuperBuild/External_*.cmake")

set(EP_GIT_PROTOCOL "https")

foreach (external_project_cmake_file ${external_project_cmake_files})
  include(${external_project_cmake_file})
endforeach()
