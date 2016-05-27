cmake_minimum_required(VERSION 3.5)
project(Nature)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GLEW REQUIRED)

find_package(GLM REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

include_directories(src)

set(SOURCE_FILES main.cpp src/nature.h src/nature.cpp src/AppRunner.cpp src/AppRunner.h src/Window.cpp src/Window.h src/Shader.cpp src/Shader.h src/ShaderProgram.cpp src/ShaderProgram.h src/Mesh.cpp src/Mesh.h)
add_executable(Nature ${SOURCE_FILES})
target_link_libraries(Nature ${GLEW_LIBRARIES} ${GLFW_STATIC_LIBRARIES} "-framework OpenGL")
