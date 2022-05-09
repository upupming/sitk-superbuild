set(proj SimpleITK)

find_package(${proj} QUIET)

if(${proj}_FOUND)
  message(STATUS "Found ${proj} at ${proj}_DIR")
else()
  message(STATUS "Adding ${proj} as external project, it will be built on build time...")
  set(EP_SOURCE_DIR ${CMAKE_BINARY_DIR}/${proj})
  # To reduce ITK folder length, we have to make it short
  set(EP_BINARY_DIR ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/S-B)
  set(SimpleITK_DIR ${EP_BINARY_DIR}/SimpleITK-build CACHE PATH "Path to dependency SimpleITK"
  FORCE)
  set(ITK_DIR ${EP_BINARY_DIR}/ITK-build CACHE PATH "Path to dependency ITK"
  FORCE)

  ExternalProject_add(${proj}-download
    GIT_REPOSITORY "${EP_GIT_PROTOCOL}://github.com/SimpleITK/SimpleITK.git"
    GIT_TAG v2.1.1.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    SOURCE_DIR ${EP_SOURCE_DIR}
    # Only download
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
  ExternalProject_add(${proj}
    # Skip download
    DOWNLOAD_COMMAND ""
    INSTALL_COMMAND ""
    SOURCE_DIR ${EP_SOURCE_DIR}/SuperBuild
    BINARY_DIR ${EP_BINARY_DIR}
    DEPENDS ${proj}-download
    CMAKE_CACHE_ARGS
      -DWRAP_PYTHON:BOOL=OFF
      -DITK_DIR:PATH=${ITK_DIR}
  )
endif()
