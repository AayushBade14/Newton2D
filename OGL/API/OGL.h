#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Newton2D/Core/Primitives.h>
#include <vector>

namespace OGL {
  bool Init();

  void SetClearColor(float r, float g, float b, float a);
  void ClearBuffers(GLenum buffers);
  
  void UpdateViewport(int width, int height);

  //void EnableDepthTesting();
  //void DisableDepthTesting();
  //void EnableDepthWrites();
  //void DisableDepthWrites();
  //void SetDepthFunction(GLenum func);
  
  //void EnableStencilTesting();
  //void DisableStencilTesting();
  //void SetStencilFunc(GLenum func, GLint ref, GLenum mask);
  //void SetStencilOperation(GLenum sfail, GLenum dpfail, GLenum dppass);
  //void SetStencilMask(GLuint mask);

  //void EnableBlending();
  //void DisableBlending();
  //void SetBlendFunction(GLenum src, GLenum dst);

  void framebuffer_size_callback(GLFWwindow* window, int width, int height);

  std::vector<float> BuildCircleVertices(const Newton2D::Circle& c, int segments = 36);
  std::vector<float> BuildRectangleVertices(const Newton2D::Rectangle& r);
  std::vector<float> BuildTriangleVertices(const Newton2D::Triangle& t);
}
