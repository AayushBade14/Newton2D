#include <Window/Window.h>

namespace Window {
  int mWidth = 1920;
  int mHeight = 1080;
  const char* mTitle = "Window";
  GLFWwindow* mWindow = nullptr;

  bool Init(int width, int height, const std::string& title){
    mWidth = width;
    mHeight = height;
    mTitle = title.c_str();

    if(glfwInit()<0){
      std::cerr<<"ERROR: GLFW::Init()!"<<std::endl;
      return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);

    if(!mWindow){
      TerminateGLFW();
      std::cerr<<"ERROR: Window::Init()!"<<std::endl;
      return false;
    }

    return true;
  } 

  void* GetWindowPointer(){return mWindow;}  
  int GetWindowWidth(){return mWidth;}
  int GetWindowHeight(){return mHeight;}
  const std::string& GetWindowTitle() const{return mTitle;}

  void PollEvents(){glfwPollEvents();}
  void SwapBuffers(){glfwSwapBuffers(mWindow);}
  void MakeContextCurrent(){glfwMakeContextCurrent(mWindow);}  
  void DestroyWindow(){glfwDestroyWindow(mWindow);}
  void TerminateGLFW(){glfwTerminate();}
}
