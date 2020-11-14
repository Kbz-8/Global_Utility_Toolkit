/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// utils.hpp
//
// AUTHOR: Malo DAVID
// CREATED: 13/11/2020
// UPDATED: 13/11/2020
/*=============================================================*/

#ifndef UTILS_HPP
#define UTILS_HPP

#ifdef __cplusplus

#include <GL/glew.h>

namespace gut
{
namespace gl
{
    void Ortho(int width, int height);
    void Perspec();
}
}

#endif // __cplusplus
#endif // UTILS_HPP
