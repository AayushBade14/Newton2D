#pragma once

#include <OGL/API/OGL.h>

namespace OGL {
  class Buffer{
    private:
      unsigned int mId;
      GLenum mTarget;

    public:
      Buffer(GLenum target);
      ~Buffer();

      const unsigned int& GetId() const {return mId;}
      GLenum GetTarget() {return mTarget;}

      void BindBuffer();
      void UnbindBuffer();

      void AllocateAndFillMemory(GLsizeiptr size, GLenum method, const void* data);
      void AllocateMemory(GLsizeiptr size, GLenum method);
      void UpdateMemory(GLsizeiptr size, GLintptr offset, const void* data);
  };
}
