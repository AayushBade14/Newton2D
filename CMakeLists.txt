cmake_minimum_required(VERSION 3.10)
project(
  Newton2D
  VERSION 1.0
  DESCRIPTION "Newton2D: The 2D Physics Engine"
  LANGUAGES C CXX
)

find_package(OpenGL REQUIRED)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Include/Newton2D/Core/glm)

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.9
)

FetchContent_MakeAvailable(glfw)

include_directories(
  ./Include
  ./Include/Newton2D/Core
  ./
)

add_library(
  glad
  STATIC
  ./OGL/glad/src/glad.c
)

target_include_directories(
  glad
  PUBLIC
  ./OGL/glad/include
)

add_library(
  ogl_api
  STATIC
  ./OGL/API/OGL.cpp
)

target_include_directories(
  ogl_api
  PUBLIC
  ./Include
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ogl_api
  PUBLIC
  glad
  glfw
)

add_library(
  ogl_buffer
  STATIC
  ./OGL/Types/Buffer.cpp
)

target_include_directories(
  ogl_buffer
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ogl_buffer
  PUBLIC
  ogl_api
)

add_library(
  ogl_shader
  STATIC
  ./OGL/Types/Shader.cpp
)

target_include_directories(
  ogl_shader
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ogl_shader
  PUBLIC
  ogl_api
  glm::glm
)

add_library(
  ogl_vao
  STATIC
  ./OGL/Types/VAO.cpp
)

target_include_directories(
  ogl_vao
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ogl_vao
  PUBLIC
  ogl_api
)

add_library(
  ogl_mesh
  STATIC
  ./OGL/Types/Mesh.cpp
)

target_include_directories(
  ogl_mesh
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  ogl_mesh
  PUBLIC
  ogl_api
  ogl_buffer
  ogl_vao
)

add_library(
  window
  STATIC
  ./Window/Window.cpp
)

target_include_directories(
  window
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  window
  PUBLIC
  glfw
)

add_library(
  gravity_sim
  STATIC
  ./Demo/GravitySim/GravitySim.cpp
)

target_include_directories(
  gravity_sim
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  gravity_sim
  PUBLIC
  ogl_api
  ogl_mesh
  ogl_shader
  window
)

add_executable(gravitysim ./Main.cpp)
target_link_libraries(
  gravitysim
  PUBLIC
  OpenGL::GL
  glad
  glfw
  glm::glm
  ogl_api
  ogl_shader
  ogl_mesh
  ogl_buffer
  ogl_vao
  window
  gravity_sim
)
