#include <OGL/API/OGL.h>

namespace OGL {
  bool Init(){
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
      std::cerr<<"ERROR: GLAD::Init()!"<<std::endl;
      return false;
    }

    return true;
  }
  
  void SetClearColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
  }

  void ClearBuffers(GLenum buffers){
    glClear(buffers);
  } 

  void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
  }

  void UpdateViewport(int width, int height){
    glViewport(0, 0, width, height);
  }
}
