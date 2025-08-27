#include <OGL/Types/Mesh.h>

namespace OGL {
  Mesh::Mesh(const std::vector<float>& vertices): mVbo(GL_ARRAY_BUFFER), mVertices(vertices){
    mVao.Bind();
    mVbo.BindBuffer();
    mVbo.AllocateAndFillMemory(mVertices.size() * sizeof(float), GL_STATIC_DRAW, mVertices.data());
    mVao.SetAttribPointer(0, 3, 3*sizeof(float), 0);
    mVao.Unbind();
  } 

  void Mesh::Draw(GLenum primitive){
    mVao.Bind();
    glDrawArrays(primitive, 0, mVertices.size()/3);
    mVao.Unbind();
  }
}
