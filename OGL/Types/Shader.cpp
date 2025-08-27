#include <OGL/Types/Shader.h>

namespace OGL {
  Shader::Shader(const std::string& vertPath, const std::string& fragPath){
    std::string vertCode = LoadFile(vertPath);
    std::string fragCode = LoadFile(fragPath);
    
    unsigned int vert = CompileShader(vertCode, ShaderType::VERT);
    unsigned int frag = CompileShader(fragCode, ShaderType::FRAG);

    CreateShaderProgram(vert, frag);
  } 

  Shader::~Shader(){
    glDeleteProgram(mId);
  }

  void Shader::Use(){
    glUseProgram(mId);
  }

  void Shader::LoadFile(const std::string& path){
    std::string code;
    std::ifstream file;

    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try{
      file.open(path);

      std::stringstream stream;
      stream << file.rdbuf();

      file.close();

      code = stream.str();
    }
    catch(const std::ifstream::failure& e){
      std::cerr<<"ERROR: ShaderFile::Read()!"<<std::endl;
    }

    return code;
  }
  
  unsigned int Shader::CompileShader(const std::string& srcCode, ShaderType type){
    const char* code = srcCode.c_str();
    int success;
    char infoLog[512];
    unsigned int shader;
    std::string st = "SHADER";

    switch (type) {
      case ShaderType::VERT:
        shader = glCreateShader(GL_VERTEX_SHADER);
        st = "VERTEX";
        break;
      case ShaderType::FRAG:
        shader = glCreateShader(GL_FRAGMENT_SHADER);
        st = "FRAGMENT";  
        break;
      default:
        std::cerr<<"ERROR: Shader Type Not Known!"<<std::endl;
        break;
    }

    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
      glGetShaderInfoLog(shader, 512, NULL, infoLog);
      std::cerr<<"ERROR: Compiling "<<st<<" Shader -> "<<infoLog<<std::endl;
    }

    return shader;
  }

  void CreateShaderProgram(unsigned int& vert, unsigned int& frag){
    int success;
    char infoLog[512];

    mId = glCreateProgram();
    glAttachShader(mId, vert);
    glAttachShader(mId, frag);
    glLinkProgram(mId);
    
    glGetProgramiv(mId, GL_LINK_STATUS, &success);
    if(!success){
      glGetProgramInfoLog(mId, 512, NULL, infoLog);
      std::cerr<<"ERROR: Linking Shader Program!"<<std::endl;
    }

    glDeleteShader(vert);
    glDeleteShader(frag);
  }
}
