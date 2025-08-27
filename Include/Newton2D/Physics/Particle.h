#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Newton2D {
  struct Particle{
    float mDamping;
    float mInverseMass;
    glm::vec3 mPosition;
    glm::vec3 mVelocity;
    glm::vec3 mAcceleration;
    
    Particle(float inversemass, float damp, const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc){
    mInverseMass = inversemass;
    mDamping = damp;
    mPosition = pos;
    mVelocity = vel;
    mAcceleration = acc;
  }
  
    void Integrate(float dt){
      mPosition += mVelocity*dt + mAcceleration*0.5f*dt*dt;
      mVelocity += mAcceleration*dt;
      mVelocity *= pow(mDamping,dt);

      if(mPosition.y < 50.0f){
        mPosition.y = 50.0f;
        mVelocity.y *= -0.8f;
      }

      else if(mPosition.y > 963.0f){
        mPosition.y = 963.0f;
        mVelocity.y *= -0.8f;
      }
    }
  };
}
