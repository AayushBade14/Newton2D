#include <Demo/GravitySim/GravitySim.h>

namespace GravitySim {
  void Run(){
    float dt = 0.0f;
    float lastFrame = 0.0f;
    double mouseX = 0.0f;
    double mouseY = 0.0f;

    if(!(Window::Init(1920, 1013, "GravitySim"))){
      std::cerr<<"ERROR: Window::Init()!"<<std::endl;
    }

    Window::MakeContextCurrent();

    if(!(OGL::Init())){
      std::cerr<<"ERROR: OGL::Init()!"<<std::endl;
    }

    Newton2D::Circle circle;
    circle.mRadius = 50.0f;
    circle.mCenter = glm::vec3(0.0f);
    
    //Newton2D::Particle particle(1.0f, 0.98f, glm::vec3(1920/2.0f,900.0f,0.0f), glm::vec3(0.0f), glm::vec3(0.0f, -981.0f, 0.0f));
  
    OGL::Mesh object(OGL::BuildCircleVertices(circle, 36));
    
    std::vector<Newton2D::Particle> particles;

    OGL::Shader shader("../Demo/GravitySim/vert.glsl","../Demo/GravitySim/frag.glsl");

    Window::SetFramebufferSizeCallback(OGL::framebuffer_size_callback);

    float cooldown = 0.0f;

    while(!(Window::GetWindowShouldClose())){
      Window::PollEvents();

      float currentFrame = (float)glfwGetTime();
      dt = currentFrame - lastFrame;
      lastFrame = currentFrame;
      cooldown -= dt; 
      OGL::SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      OGL::ClearBuffers(GL_COLOR_BUFFER_BIT);
      
      glfwGetCursorPos((GLFWwindow*)Window::GetWindowPointer(), &mouseX, &mouseY);
      mouseY = 1013.0f - mouseY;

      if(glfwGetMouseButton((GLFWwindow*)Window::GetWindowPointer(),GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS && cooldown <= 0.0f){
        Newton2D::Particle p(1.0f, 0.99f, glm::vec3(mouseX, mouseY, 0.0f), glm::vec3(0.0f),glm::vec3(0.0f, -981.0f, 0.0f));
        particles.push_back(p);
        cooldown = 0.2f;
      }
      //particle.Integrate(dt);
    
      glm::mat4 view = glm::mat4(1.0f);
      glm::mat4 projection = glm::ortho(0.0f, 1920.0f, 0.0f, 1013.0f);
      
      shader.Use();
      shader.SetValue("view", view);
      shader.SetValue("projection", projection);

      for(unsigned int i = 0; i < particles.size(); i++){
        particles[i].Integrate(dt);
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, particles[i].mPosition); 
        shader.SetValue("model", model);
        shader.SetValue("pos",particles[i].mPosition);
        object.Draw(GL_TRIANGLES);  
      }


      //object.Draw(GL_TRIANGLES);

      Window::SwapBuffers();
    }

    Window::DestroyWindow();
    Window::TerminateGLFW();
  }
}
