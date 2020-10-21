/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// GUT.cpp
//
// AUTHOR: DAVID Malo
// CREATED: 11/09/2020
// UPDATED: 11/09/2020
/*=============================================================*/

#include "GUT.hpp"

#ifdef __cplusplus

void GUT::debugPrint(const char* text)
{
    std::cout << text << std::endl;
}

int GUT::randint(int a, int b)
{
    return rand() % (b - a) + a;
}

#endif //__cplusplus
