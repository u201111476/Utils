cmake_minimum_required(VERSION 3.0)

set(target WjUtils)

if(MAJOR_VERSION)
message("major version is " ${MAJOR_VERSION} "!")
add_compile_definitions(MAJOR_VERSION=${MAJOR_VERSION})
endif()

if (MINOR_VERSION)
message("minor version is " ${MINOR_VERSION} "!")
add_compile_definitions(MINOR_VERSION=${MINOR_VERSION})
endif()

if(PATCH_VERSION)
message("patch version is " ${PATCH_VERSION} "!")
add_compile_definitions(PATCH_VERSION=${PATCH_VERSION})
endif()

project(${target} VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

set(VERSION_REVISION 1)
# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_CXX_COMPILER x86)
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

add_compile_definitions(PRODUCT_VERSION="${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
# include_directories(src)

file(GLOB SRC_LIST 
  "*.cpp"
)

file(GLOB HEADER_LIST
  "*.h"
)

if(MSVC)
    message(status ${CMAKE_CURRENT_SOURCE_DIR})
    set(MY_VERSIONINFO_RC "${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.rc")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.rc.in"
                    "${MY_VERSIONINFO_RC}")
endif()

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

add_library(${target} SHARED
  ${HEADER_LIST}
  ${SRC_LIST}
  ${MY_VERSIONINFO_RC}
)