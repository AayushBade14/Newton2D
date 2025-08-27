#include <Demo/GravitySim/GravitySim.h>

namespace GravitySim {
  void Run(){
    float dt = 0.0f;
    float lastFrame = 0.0f;

    if(!(Window::Init(1920, 1013, "GravitySim"))){
      std::cerr<<"ERROR: Window::Init()!"<<std::endl;
    }

    Window::MakeContextCurrent();

    if(!(OGL::Init())){
      std::cerr<<"ERROR: OGL::Init()!"<<std::endl;
    }

    Newton2D::Circle circle;
    circle.mRadius = 50.0f;
    circle.mCenter = glm::vec3(1920/2.0f, 900.0f, 0.0f);

    OGL::Mesh object(OGL::BuildCircleVertices(circle, 36));
    
    Shader shader("./vert.glsl","./frag.glsl");

    Window::SetFramebufferSizeCallback(OGL::framebuffer_size_callback);

    while(!(Window::GetWindowShouldClose())){
      Window::PollEvents();

      float currentFrame = (float)glfwGetTime();
      dt = currentFrame - lastFrame;
      lastFrame = currentFrame;
      
      OGL::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      OGL::ClearBuffers(GL_COLOR_BUFFER_BIT);

      glm::mat4 model = glm::mat4(1.0f);
      glm::mat4 view = glm::mat4(1.0f);
      glm::mat4 projection = glm::ortho(0.0f, 1920.0f, 0.0f, 1013.0f);

      shader.Use();
      shader.SetValue("model", model);
      shader.SetValue("view", view);
      shader.SetValue("projection", projection);

      object.Draw(GL_TRIANGLES);

      Window::SwapBuffers();
    }

    Window::DestroyWindow();
    Window::TerminateGLFW();
  }
}
