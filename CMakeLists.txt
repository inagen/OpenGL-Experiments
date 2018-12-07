cmake_minimum_required(VERSION 2.8)

project(test)
add_executable(test main.cpp glad.c)


find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS})

target_link_libraries(test ${OPENGL_LIBRARIES})
