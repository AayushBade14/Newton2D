#include <OGL/Types/Buffer.h>

namespace OGL {
  Buffer::Buffer(GLenum target){
    glGenBuffers(1, &mId);
    mTarget = target;
  }

  Buffer::~Buffer(){
    glDeleteBuffers(1, &mId);
  }

  void Buffer::BindBuffer(){
    glBindBuffer(mTarget, mId);
  }

  void Buffer::UnbindBuffer(){
    glBindBuffer(mTarget, 0);
  }

  void Buffer::AllocateAndFillMemory(GLsizeiptr size, GLenum method, const void* data){
    glBufferData(mTarget, size, data, method);
  }

  void Buffer::AllocateMemory(GLsizeiptr size, GLenum method){
    glBufferData(mTarget, size, NULL, method);
  }

  void Buffer::UpdateMemory(GLsizeiptr size, GLintptr offset, const void* data){
    glBufferSubData(mTarget, offset, size, data);
  }
}
