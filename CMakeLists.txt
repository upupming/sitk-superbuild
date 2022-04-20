cmake_minimum_required(VERSION 3.21.1)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/install CACHE PATH "Install prefix" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

set(top_level_proj sitk-superbuild)
project(${top_level_proj})

include("${CMAKE_CURRENT_SOURCE_DIR}/SuperBuild.cmake")

add_executable(${top_level_proj} main.cpp)
find_package(SimpleITK CONFIG REQUIRED)
target_link_libraries(${top_level_proj} ${SimpleITK_LIBRARIES})
