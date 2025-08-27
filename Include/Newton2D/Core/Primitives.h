#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Newton2D {
  
  struct Circle{
    float mRadius;
    glm::vec3 mCenter;
  };

  struct Rectangle{
    glm::vec3 mOrigin;
    glm::vec3 mSize;
  };
  
  struct OrientedRectangle{
    float mRotation;
    glm::vec3 mCenter;
    glm::vec3 mHalfExtend;
  };

  struct Triangle{
    glm::vec3 mP1;
    glm::vec3 mP2;
    glm::vec3 mP3;
  };

  struct Line{
    glm::vec3 mBase;
    glm::vec3 mDirection;
  };

  struct LineSegment{
    glm::vec3 mP1;
    glm::vec3 mP2;
  };
}
