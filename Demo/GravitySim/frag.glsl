#version 460 core

out vec4 fragColor;

uniform vec3 pos;

void main(){
  vec2 st = gl_FragCoord.xy/vec2(1920.0,1013.0);
  vec2 p = vec2(pos.x,pos.y)/vec2(1920.0,1013.0);
  
  float dist = distance(st,p);
  float t = smoothstep(0.08, 0.0, dist);
  vec3 color = mix(vec3(1.0,0.0,0.0),vec3(1.0, 0.5, 0.2),t);

  fragColor = vec4(color, 1.0);
}
