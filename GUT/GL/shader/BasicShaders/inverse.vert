/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// inverse.vert
//
// Simple shader in GLSL for basic programs.
//
// AUTHOR: Malo DAVID
// CREATED: 14/11/2020
// UPDATED: 21/11/2020
/*=============================================================*/

#version 330 core

out vec4 Color;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

uniform mat4 proj;

void main(void)
{
  Color = aColor;
  gl_Position = proj * vec4(aPos, 1.0f);
}
