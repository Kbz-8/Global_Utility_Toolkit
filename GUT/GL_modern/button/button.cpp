/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// button.cpp
//
// AUTHOR: Malo DAVID
// CREATED: 04/11/2020
// UPDATED: 23/01/2021
/*=============================================================*/

#ifdef __cplusplus

#include "button.hpp"

namespace gut
{
namespace gl3
{
    Button::Button(int pos_x, int pos_y, int width, int height, const char* text, const char* path, unsigned int sizeFont) : Text(path, sizeFont, WHITE)
    {
        _pos_x = pos_x;
        _pos_y = pos_y;
        _pos_w = width;
        _pos_h = height;

        Init(text);
    }

    Button::Button(int pos_x, int pos_y, int width, int height, const char* text, TTF_Font *font) : Text(font, WHITE)
    {
        _pos_x = pos_x;
        _pos_y = pos_y;
        _pos_w = width;
        _pos_h = height;

        Init(text);
    }

    void Button::updateButton(int mouse_posx, int mouse_posy, bool isButtonDown, bool isbuttonUp, int ratioCorrecteur)
    {
        resetFunction();

        if(_ratioCorrecteur != ratioCorrecteur)
            _ratioCorrecteur = ratioCorrecteur;

        if(    mouse_posy >  _pos_y
            && mouse_posy <= _pos_y + _pos_h
            && mouse_posx >  _pos_x
            && mouse_posx <= _pos_x + _pos_w
            && isButtonDown)
            _button_down = true;
        if(isbuttonUp)
            _button_down = false;

        if(    mouse_posy >  _pos_y
            && mouse_posy <= _pos_y + _pos_h
            && mouse_posx >  _pos_x
            && mouse_posx <= _pos_x + _pos_w)
            _activate = true;
        else
            _activate = false;


        if(_activate && isbuttonUp)
            _function = true;
        else
            _function = false;
    }

    void Button::renderButton()
    {
        float vertices[8] = {
                _pos_x, _pos_y,
                _pos_x + _pos_w,  _pos_y,
                _pos_x + _pos_w,  _pos_y + _pos_h,
                _pos_x,  _pos_y + _pos_h
        };

        if(_activate)
            color4f(0.4, 0.4, 0.4, 1.0, sizeof(vertices));
        else
            color4f(0.3, 0.3, 0.3, 1.0, sizeof(vertices));
        if(_button_down)
            color4f(0.1, 0.1, 0.1, 1.0, sizeof(vertices));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)vertices);

        glDrawArrays(GL_QUADS, 0, sizeof(vertices));

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    }

    void Button::rescale(int pos_x, int pos_y, int width, int height)
    {
        _pos_x = pos_x;
        _pos_y = pos_y;
        _pos_w = width;
        _pos_h = height;
    }

    void Button::updateTexte()
    {
        render(_pos_x + (_pos_w - _surf_wid.front())/2, _pos_y + _ratioCorrecteur + (_pos_h - _surf_hei.front())/2);
    }

    bool Button::getActivation()
    {
        return _function;
    }

    void Button::resetFunction()
    {
        _function = false;
    }

    Button::~Button() {}
}
}

#endif // __cplusplus
