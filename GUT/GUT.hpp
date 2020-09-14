/*=============================================================*/
// Global Utilitie Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// GUT.hpp
//
// AUTHOR: DAVID Malo
// CREATED: 11/09/2020
// UPDATED: 12/09/2020
/*=============================================================*/

#ifndef __GUT_HPP__
#define __GUT_HPP__

#ifdef __cplusplus  // only available for C++

#include "math/Vec3/Vec3.hpp"
#include "math/Vec2/vec2.hpp"
#include "Log/log.hpp"
#include "GL/getPixelColor/getpixelcolor.hpp"

#include <iostream>


/* shortcuts for variable types */
typedef unsigned int GUTuint;
typedef unsigned long GUTulong;
typedef unsigned long long GUTulonglong;
typedef unsigned short GUTushort;
typedef unsigned char GUTuchar;
typedef const char* GUTtext;

void debugPrint(const char* text = "debug");  // test print for debugging
int randint(int a, int b);  // gives a random integer

#endif // __cplusplus
#endif // __GUT_HPP__
