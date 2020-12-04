/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// main.vert
//
// Simple shader in GLSL for basic programs.
//
// AUTHOR: Malo DAVID
// CREATED: 14/11/2020
// UPDATED: 21/11/2020
/*=============================================================*/

#version 330 core

out vec2 texCoords;
out vec4 Color;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 texCoordIn;

uniform mat4 view;
uniform mat4 proj;
uniform mat4 model;

void main(void)
{
  vec3 fragPos = vec3(model * aPos);
  Color = aColor;
  texCoords = texCoordIn;

  if(view = mat4(1.0))
    gl_Position = proj * vec4(aPos, 1.0f);
  else
    gl_Position = proj * view * vec4(fragPos, 1.0f);
}
