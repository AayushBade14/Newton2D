#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace Window {

  bool Init(int width, int height, const std::string& title);
  
  void* GetWindowPointer();
  bool GetWindowShouldClose();

  int GetWindowWidth();
  int GetWindowHeight();
  const std::string& GetWindowTitle() const;

  void PollEvents();
  void SwapBuffers();
  
  void MakeContextCurrent();

  void DestroyWindow();
  void TerminateGLFW();
}
