#include <OGL/Types/VAO.h>

namespace OGL {
  VAO::VAO(){
    glGenVertexArrays(1, &mId);
  }

  VAO::~VAO(){
    glDeleteVertexArrays(1, &mId);
  }

  void VAO::Bind(){
    glBindVertexArray(mId);
  }

  void VAO::Unbind(){
    glBindVertexArray(0);
  }

  void VAO::SetAttribPointer(GLuint loc, GLint nr, GLsizei stride, GLuint start){
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, nr, GL_FLOAT, GL_FALSE, stride, (void*)start);
  }
}
