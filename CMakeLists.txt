cmake_minimum_required(VERSION 2.8)

project(test)
add_executable(test src/main.cpp 
					src/glad.c
					src/window.cpp
					src/shader.cpp)


find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS})

target_link_libraries(test ${OPENGL_LIBRARIES})
