/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// utils.cpp
//
// Use these functions with glm
//
// AUTHOR: Malo DAVID
// CREATED: 13/11/2020
// UPDATED: 23/01/2021
/*=============================================================*/

#include "utils.hpp"

#ifdef __cplusplus

glm::mat4 GUTprojection;
glm::mat4 GUTmodel;
glm::mat4 GUTview;

unsigned char ACTIVE_MATRIX;

namespace gut
{
namespace gl3
{
    void perspective(float FOV, float aspect, float near, float far)
    {
        GUTprojection = glm::perspective(glm::radians(FOV), aspect, near, far);
    }

    void ortho(float width, float height)
    {
        GUTprojection = glm::ortho(0.0f, width, height, 0.0f);
    }

    void MatrixMode(int type)
    {
        ACTIVE_MATRIX = type;
    }

    glm::mat4 getMatrix(int type)
    {
        switch(type)
        {
            case GUT_PROJECTION_MATRIX:    return GUTprojection;
            case GUT_MODEL_MATRIX:         return GUTmodel;
            case GUT_VIEW_MATRIX:          return GUTview;

            default: break;
        }
    }

    glm::mat4 getCurrentMatrix()
    {
        switch(ACTIVE_MATRIX)
        {
            case GUT_PROJECTION_MATRIX: return GUTprojection;
            case GUT_MODEL_MATRIX:      return GUTmodel;
            case GUT_VIEW_MATRIX:       return GUTview;

            default: break;
        }
    }

    void lookAt(float pos_x, float pos_y, float pos_z, float target_x, float target_y, float target_z, float up_x, float up_y, float up_z)
    {
        GUTview = glm::lookAt(glm::vec3(pos_x, pos_y, pos_z), glm::vec3(target_x, target_y, target_z), glm::vec3(up_x, up_y, up_z));
    }

    void LoadIdentity()
    {
        switch(ACTIVE_MATRIX)
        {
            case GUT_PROJECTION_MATRIX: GUTprojection = glm::mat4(1.0f); break;
            case GUT_MODEL_MATRIX:      GUTmodel = glm::mat4(1.0f);      break;
            case GUT_VIEW_MATRIX:       GUTview = glm::mat4(1.0f);       break;

            default: break;
        }
    }

    void Translate3D(double x, double y, double z)
    {
        GUTmodel = glm::translate(GUTmodel, glm::vec3(x, y, z));
    }

    void color4f(float r, float g, float b, float a, int verticesNumber)
    {
        float pointer[verticesNumber * 6 * 4];
        for(int i = 0; i < verticesNumber * 6 * 4; i++)
        {
            pointer[4 * i] = r;
            pointer[4 * i + 1] = g;
            pointer[4 * i + 2] = b;
            pointer[4 * i + 3] = a;
        }
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, &pointer);
    }

    float getGLversion()
    {
        std::string getter = std::string(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
        return std::stof(getter);
    }
    float getGLSLversion()
    {
        std::string getter = std::string(reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));
        return std::stof(getter);
    }
}
}

#endif // __cplusplus
