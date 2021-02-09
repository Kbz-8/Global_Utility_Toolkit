/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// vec2.hpp
//
// Class for 2D vectors
//
// AUTHOR: Malo DAVID
// CREATED: 11/09/2020
// UPDATED: 08/02/2021
/*=============================================================*/

#ifndef Vec2_HPP_INCLUDED
#define Vec2_HPP_INCLUDED

#ifdef __cplusplus

#include <iostream>
#include <cmath>

namespace gut
{
namespace math
{
    /* ============================================================== Déclaration ============================================================== */

    // Prototypes
    template <class T>
    struct Vec2;
    template<typename T>
    std::ostream& operator<<(std::ostream&, const Vec2<T>&);

    // Classe
    template <class T>
    struct Vec2
    {
        T X;
        T Y;

        Vec2();
        Vec2(T x, T y);
        Vec2(const Vec2 & v);
        Vec2(const Vec2 & from, const Vec2 & to);

        Vec2 & operator= (const Vec2 & v);

        bool operator== (const Vec2 & v);
        bool operator!= (const Vec2 & v);

        bool operator== (const T valeur);
        bool operator!= (const T valeur);

        Vec2 & operator+= (const Vec2 & v);
        Vec2 operator+ (const Vec2 & v) const;
        Vec2 operator+ (const T valeur);

        Vec2 & operator-= (const Vec2 & v);
        Vec2 operator- (const Vec2 & v) const;
        Vec2 operator- (const T valeur);

        Vec2 & operator*= (const T a);
        Vec2 operator* (const T a)const;
        friend Vec2 operator* (const T a, const Vec2 & v);
        Vec2 & operator* (const Vec2 &v);

        Vec2 & operator/= (const T a);
        Vec2 operator/ (const T a)const;

        bool operator< (const Vec2 &v);
        bool operator< (const T valeur);

        bool operator> (const Vec2 &v);
        bool operator> (const T valeur);

        bool operator<= (const Vec2 &v);
        bool operator<= (const T valeur);

        bool operator>= (const Vec2 &v);
        bool operator>= (const T valeur);

        Vec2 crossProduct(const Vec2 & v)const;
        double length()const;
        Vec2 & normalize();

        Vec2 COPY(const Vec2 &v);
        Vec2 DirectCopy();

        Vec2 SET(T x, T y);

        friend std::ostream & operator<<(std::ostream& target, const Vec2& source);

        Vec2 NEGATE();
        Vec2 NEGATEprecisely(bool x, bool y);

        double dot(Vec2 v);
    };

    /* ============================================================== Définition ============================================================== */

    template <class T>
    Vec2<T>::Vec2()
    {
        X = 0;
        Y = 0;
    }

    template <class T>
    Vec2<T>::Vec2(T x, T y)
    {
        X = x;
        Y = y;
    }

    template <class T>
    Vec2<T>::Vec2(const Vec2<T> & v)
    {
        X = v.X;
        Y = v.Y;
    }

    template <class T>
    Vec2<T>::Vec2(const Vec2<T> & from, const Vec2<T> & to)
    {
        X = to.X - from.X;
        Y = to.Y - from.Y;
    }

    template <class T>
    Vec2<T> & Vec2<T>::operator= (const Vec2<T> & v)
    {
        X = v.X;
        Y = v.Y;
        return *this;
    }

    template <class T>
    bool Vec2<T>::operator== (const Vec2<T> & v)
    {
        if(X == v.X && Y == v.Y)
            return true;
        return false;
    }

    template <class T>
    bool Vec2<T>::operator!= (const Vec2<T> & v)
    {
        if(X != v.X && Y != v.Y)
            return true;
        return false;
    }



    template <class T>
    bool Vec2<T>::operator== (const T valeur)
    {
        if(X == valeur && Y == valeur)
            return true;
        return false;
    }

    template <class T>
    bool Vec2<T>::operator!= (const T valeur)
    {
        if(X != valeur && Y != valeur)
            return true;
        return false;
    }

    template <class T>
    Vec2<T> & Vec2<T>::operator+= (const Vec2<T> & v)
    {
        X += v.X;
        Y += v.Y;
        return *this;
    }

    template <class T>
    Vec2<T> Vec2<T>::operator+ (const Vec2<T> & v) const
    {
        Vec2<T> t = *this;
        t += v;
        return t;
    }

    template <class T>
    Vec2<T> Vec2<T>::operator+ (const T valeur)
    {
        X += valeur;
        Y += valeur;
        return *this;
    }

    template <class T>
    Vec2<T> & Vec2<T>::operator-= (const Vec2<T> & v)
    {
        X -= v.X;
        Y -= v.Y;
        return *this;
    }

    template <class T>
    Vec2<T> Vec2<T>::operator- (const Vec2<T> & v) const
    {
        Vec2<T> t = *this;
        t -= v;
        return t;
    }

    template <class T>
    Vec2<T> Vec2<T>::operator- (const T valeur)
    {
        X -= valeur;
        Y -= valeur;
        return *this;
    }

    template <class T>
    Vec2<T> & Vec2<T>::operator*= (const T a)
    {
        X *= a;
        Y *= a;
        return *this;
    }

    template <class T>
    Vec2<T> Vec2<T>::operator* (const T a)const
    {
        Vec2<T> t = *this;
        t *= a;
        return t;
    }

    template <class T>
    Vec2<T> operator* (const T a, const Vec2<T> & v)
    {
        return Vec2<T>(v.X*a, v.Y*a);
    }

    template <class T>
    Vec2<T> & Vec2<T>::operator* (const Vec2<T> &v)
    {
        X *= v.X;
        Y *= v.Y;
        return *this;
    }

    template <class T>
    Vec2<T> & Vec2<T>::operator/= (const T a)
    {
        X /= a;
        Y /= a;
        return *this;
    }

    template <class T>
    Vec2<T> Vec2<T>::operator/ (const T a)const
    {
        Vec2<T> t = *this;
        t /= a;
        return t;
    }

    template <class T>
    bool Vec2<T>::operator< (const Vec2<T> &v)
    {
        if(X < v.X && Y < v.Y)
            return true;
        return false;
    }
    template <class T>
    bool Vec2<T>::operator< (const T valeur)
    {
        if(X < valeur && Y < valeur)
            return true;
        return false;
    }




    template <class T>
    bool Vec2<T>::operator> (const Vec2<T> &v)
    {
        if(X > v.X && Y > v.Y)
            return true;
        return false;
    }
    template <class T>
    bool Vec2<T>::operator> (const T valeur)
    {
        if(X > valeur && Y > valeur)
            return true;
        return false;
    }




    template <class T>
    bool Vec2<T>::operator<= (const Vec2<T> &v)
    {
        if(X <= v.X && Y <= v.Y)
            return true;
        return false;
    }
    template <class T>
    bool Vec2<T>::operator<= (const T valeur)
    {
        if(X <= valeur && Y <= valeur)
            return true;
        return false;
    }




    template <class T>
    bool Vec2<T>::operator>= (const Vec2<T> &v)
    {
        if(X >= v.X && Y >= v.Y)
            return true;
        return false;
    }
    template <class T>
    bool Vec2<T>::operator>= (const T valeur)
    {
        if(X >= valeur && Y >= valeur)
            return true;
        return false;
    }



    template <class T>
    Vec2<T> Vec2<T>::crossProduct(const Vec2<T> & v)const
    {
        return Vec2<T>(v.Y, -v.X);
    }

    template <class T>
    double Vec2<T>::length()const
    {
        return sqrt(X*X + Y*Y);
    }

    template <class T>
    Vec2<T> & Vec2<T>::normalize()
    {
        (*this) /= length();
        return (*this);
    }

    template <class T>
    Vec2<T> Vec2<T>::COPY(const Vec2<T> &v)
    {
        X = v.X;
        Y = v.Y;

        return *this;
    }

    template <class T>
    Vec2<T> Vec2<T>::DirectCopy()
    {
        Vec2<T> cop;
        cop.X = X;
        cop.Y = Y;
        return cop;
    }

    template <class T>
    Vec2<T> Vec2<T>::SET(T x, T y)
    {
        X = x;
        Y = y;

        return *this;
    }

    template <class T>
    std::ostream & operator<<(std::ostream& target, const Vec2<T>& source)
    {
        target << source.X << ", " << source.Y;
        return target;
    }

    template <class T>
    Vec2<T> Vec2<T>::NEGATE()
    {
        X = -X;
        Y = -Y;
        return *this;
    }

    template <class T>
    Vec2<T> Vec2<T>::NEGATEprecisely(bool x, bool y)
    {
        if(x) X = -X;
        if(y) Y = -Y;

        return *this;
    }

    template <class T>
    double Vec2<T>::dot(Vec2<T> v)
    {
        return X * v.X + Y * v.Y;
    }
}
}

#endif // __cplusplus
#endif
