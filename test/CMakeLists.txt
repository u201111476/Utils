cmake_minimum_required(VERSION 3.0)

set(target Test)
project(${target})

# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_CXX_COMPILER x86)
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG /OPT:REF /OPT:ICF")

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

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

add_compile_definitions(PRODUCT_VERSION="${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")

file(GLOB SRC_LIST 
  "*.cpp"
)

file(GLOB HEADER_LIST
  "*.h"
)

if(${CMAKE_BUILD_TYPE} MATCHES "debug")
    link_directories(../bin/Debug)
else()
    link_directories(../bin/Release)
endif()


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)


add_executable(${target} ${SRC_LIST} ${HEADER_LIST})

add_dependencies(${target} WjUtils)

target_link_libraries(${target}
    WjUtils.lib
)
