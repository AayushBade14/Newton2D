#pragma once

#include <OGL/API/OGL.h>

namespace OGL {
  class VAO{
    private:
      unsigned int mId;

    public:
      VAO();
      ~VAO();
      
      const unsigned int& GetId() const {return mId;}

      void Bind();
      void Unbind();

      void SetAttribPointer(GLuint loc, GLint size, GLsizei stride, GLuint start);
  };
}
