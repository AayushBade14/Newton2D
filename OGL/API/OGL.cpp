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

  std::vector<float> BuildCircleVertices(const Circle& c, int segments){
    std::vector<float> circle;
    const float PI = 3.141f;
    const float TWO_PI = 2*PI;
    float cx = 0.0f;
    float cy = 0.0f;
    float cz = 0.0f;
    for(int i = 0; i < segments; i++){
      float theta1 = i * (TWO_PI/segments);
      float theta2 = (i + 1) * (TWO_PI/segments);

      circle.push_back(c.mCenter.x);
      circle.push_back(c.mCenter.y);
      circle.push_back(c.mCenter.z);

      circle.push_back(c.mCenter.x + c.mRadius*cos(theta1));
      circle.push_back(c.mCenter.y + c.mRadius*sin(theta1));
      circle.push_back(0.0f);
      
      circle.push_back(c.mCenter.x + c.mRadius*cos(theta2));
      circle.push_back(c.mCenter.y + c.mRadius*sin(theta2));
      circle.push_back(0.0f);
    }

    return circle;
  } 

  std::vector<float> BuildRectangleVertices(const Rectangle& r){
    std::vector<float> rect;

    rect.push_back(r.mOrigin.x);
    rect.push_back(r.mOrigin.y);
    rect.push_back(0.0f);

    rect.push_back(r.mOrigin.x + r.mSize.x);
    rect.push_back(r.mOrigin.y + 0.0f);
    rect.push_back(0.0f);

    rect.push_back(r.mOrigin.x + 0.0f);
    rect.push_back(r.mOrigin.y + r.mSize.y);
    rect.push_back(0.0f);

    rect.push_back(r.mOrigin.x + 0.0f);
    rect.push_back(r.mOrigin.y + r.mSize.y);
    rect.push_back(0.0f);

    rect.push_back(r.mOrigin.x + r.mSize.x);
    rect.push_back(r.mOrigin.y + 0.0f);
    rect.push_back(0.0f);

    rect.push_back(r.mOrigin.x + r.mSize.x);
    rect.push_back(r.mOrigin.y + r.mSize.y);
    rect.push_back(0.0f);
    
    return rect;
  }

  std::vector<float> BuildTriangleVertices(const Triangle& t){
    std::vector<float> tri;

    tri.push_back(t.mP1.x);
    tri.push_back(t.mP1.y);
    tri.push_back(t.mP1.z);

    tri.push_back(t.mP2.x);
    tri.push_back(t.mP2.y);
    tri.push_back(t.mP2.z);

    tri.push_back(t.mP3.x);
    tri.push_back(t.mP3.y);
    tri.push_back(t.mP3.z);
  }
}
