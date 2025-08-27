#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
}
