#pragma once

#include <OGL/API/OGL.h>
#include <OGL/Types/Buffer.h>
#include <OGL/Types/VAO.h>

namespace OGL {
  class Mesh{
    private:
      std::vector<float> mVertices;
      Buffer mVbo;
      VAO mVao;
    
    public:
      Mesh(const std::vector<float>& vertices);
      ~Mesh()=default;

      void Draw(GLenum primitive);
  };
}
