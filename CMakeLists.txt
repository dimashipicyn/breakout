cmake_minimum_required(VERSION 3.20.0)
project(breakout)

add_compile_options(-Wall)
if (MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Y-")
else()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winvalid-pch")
endif()

add_executable(${PROJECT_NAME})
add_subdirectory(src)
add_subdirectory(2dCpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
	2dCpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
	2dCpp/include
)

