cmake_minimum_required(VERSION 3.0.0)

set(VCPKG_ROOT_DIR "$ENV{VCPKG_ROOT}" CACHE PATH "VCPKG_ROOT_DIR")

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT_DIR}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

add_compile_options(-Wall -Wextra -pedantic)

if (WIN32)
    set(VCPKG_SYSARCH "x64-windows")
elseif(APPLE)
    set(VCPKG_SYSARCH "x64-osx")
else()
    set(VCPKG_SYSARCH "x64-linux")
endif()

set(VCPKG_PREFIX_PATH "${VCPKG_ROOT_DIR}/installed/${VCPKG_SYSARCH}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(VCPKG_PREFIX_CONF_PATH "${VCPKG_PREFIX_PATH}/debug")
else()
    set(VCPKG_PREFIX_CONF_PATH "${VCPKG_PREFIX_PATH}")
endif()

project(breakout)

add_compile_options(-Wall -Wextra -pedantic)

set(SOURCE_FILES
	src/main.cpp
	src/simple_scene.cpp
	src/ball.cpp
)

set(HEADER_FILES 
	src/simple_scene.hpp
	src/ball.hpp
)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(2dCpp PRIVATE)

#set(2dCpp_DIR 2dCpp/build)
#find_package(2dCpp REQUIRED)

add_executable(${PROJECT_NAME} 
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	2dCpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
	2dCpp/include
	${VCPKG_PREFIX_PATH}/include
)

