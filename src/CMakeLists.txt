cmake_minimum_required(VERSION 3.21.1)

set(proj sitk-superbuild)
project(${proj})

add_executable(${proj} main.cpp)
find_package(SimpleITK CONFIG REQUIRED)
target_link_libraries(${proj} ${SimpleITK_LIBRARIES})

target_include_directories(${proj} PUBLIC ../lib)
