cmake_minimum_required(VERSION 3.20.0)
project(breakout)

add_compile_options(-Wall)

set(SOURCE_FILES
	src/main.cpp
	src/simple_scene.cpp
	src/ball.cpp
	src/Rocket.cpp
	src/Block.cpp
	src/Level.cpp
	src/menu_scene.cpp
)

set(HEADER_FILES 
	src/simple_scene.hpp
	src/ball.hpp
	src/Rocket.hpp
	src/Block.hpp
	src/Level.hpp
	src/menu_scene.h
)

add_subdirectory(2dCpp)

add_executable(${PROJECT_NAME} 
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	2dCpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
	2dCpp/include
)

