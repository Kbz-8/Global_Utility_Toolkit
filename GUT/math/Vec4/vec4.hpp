/*=============================================================*/
// Global Utility Toolkit
// GUT is a global extension for C++. It simplifies the development of 3D programs (especially with OpenGL).
// It can also be used in simple programs.
//
// vec4.hpp
//
// Class for 4D vectors
//
// AUTHOR: Malo DAVID
// CREATED: 09/10/2020
// UPDATED: 07/02/2021
/*=============================================================*/

#ifndef VEC4_HPP
#define VEC4_HPP

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
    struct Vec4;
    template<typename T>
    std::ostream& operator<<(std::ostream&, const Vec4<T>&);

    // Classe
    template <class T>
    struct Vec4
    {
        T X;
        T Y;
        T Z;
        T W;

        Vec4();
        Vec4(T x,T y,T z, T w);
        Vec4(const Vec4 & v);
        Vec4(const Vec4 & from, const Vec4 & to);

        Vec4 & operator= (const Vec4 & v);

        bool operator== (const Vec4 & v);
        bool operator!= (const Vec4 & v);

        bool operator== (const T valeur);
        bool operator!= (const T valeur);

        Vec4 & operator+= (const Vec4 & v);
        Vec4 operator+ (const Vec4 & v) const;
        Vec4 operator+ (const T valeur);

        Vec4 & operator-= (const Vec4 & v);
        Vec4 operator- (const Vec4 & v) const;
        Vec4 operator- (const T valeur);

        Vec4 & operator*= (const T a);
        Vec4 operator* (const T a)const;
        friend Vec4 operator* (const T a,const Vec4 & v);
        Vec4 & operator* (const Vec4 &v);

        Vec4 & operator/= (const T a);
        Vec4 operator/ (const T a)const;

        bool operator< (const Vec4 &v);
        bool operator< (const T valeur);

        bool operator> (const Vec4 &v);
        bool operator> (const T valeur);

        bool operator<= (const Vec4 &v);
        bool operator<= (const T valeur);

        bool operator>= (const Vec4 &v);
        bool operator>= (const T valeur);

        Vec4 crossProduct(const Vec4 & v)const;
        double length()const;
        Vec4 & normalize();

        Vec4 COPY(const Vec4 &v);
        Vec4 DirectCopy();

        Vec4 SET(T x, T y, T z, T w);

        friend std::ostream& operator<< <T> (std::ostream&, const Vec4&);

        Vec4 NEGATE();
        Vec4 NEGATEprecisely(bool x, bool y, bool z, bool w);

        double dot(Vec4 v);
    };

/* ============================================================== Définition ============================================================== */

    template <class T>
    Vec4<T>::Vec4()
    {
        X = 0;
        Y = 0;
        Z = 0;
        W = 0;
    }
    template <class T>
    Vec4<T>::Vec4(T x, T y, T z, T w)
    {
        X = x;
        Y = y;
        Z = z;
        W = w;
    }
    template <class T>
    Vec4<T>::Vec4(const Vec4<T> & v)
    {
        X = v.X;
        Y = v.Y;
        Z = v.Z;
    }
    template <class T>
    Vec4<T>::Vec4(const Vec4 & from, const Vec4<T> & to)
    {
        X = to.X - from.X;
        Y = to.Y - from.Y;
        Z = to.Z - from.Z;
        W = to.W - from.W;
    }
    template <class T>
    Vec4<T> & Vec4<T>::operator= (const Vec4<T> & v)
    {
        X = v.X;
        Y = v.Y;
        Z = v.Z;
        W = v.W;
        return *this;
    }
    template <class T>
    bool Vec4<T>::operator== (const Vec4<T> & v)
    {
        if(X == v.X && Y == v.Y && Z == v.Z && W == v.W)
            return true;
        return false;
    }
    template <class T>
    bool Vec4<T>::operator!= (const Vec4<T> & v)
    {
        if(X != v.X && Y != v.Y && Z != v.Z && W != v.W)
            return true;
        return false;
    }


    template <class T>
    bool Vec4<T>::operator== (const T valeur)
    {
        if(X == valeur && Y == valeur && Z == valeur && W == valeur)
            return true;
        return false;
    }
    template <class T>
    bool Vec4<T>::operator!= (const T valeur)
    {
        if(X != valeur && Y != valeur && Z != valeur && W != valeur)
            return true;
        return false;
    }
    template <class T>
    Vec4<T> & Vec4<T>::operator+= (const Vec4<T> & v)
    {
        X += v.X;
        Y += v.Y;
        Z += v.Z;
        W += v.W;
        return *this;
    }
    template <class T>
    Vec4<T> Vec4<T>::operator+ (const Vec4<T> & v) const
    {
        Vec4 t = *this;
        t += v;
        return t;
    }
    template <class T>
    Vec4<T> Vec4<T>::operator+ (const T valeur)
    {
        X += valeur;
        Y += valeur;
        Z += valeur;
        W += valeur;
        return *this;
    }
    template <class T>
    Vec4<T> & Vec4<T>::operator-= (const Vec4<T> & v)
    {
        X -= v.X;
        Y -= v.Y;
        Z -= v.Z;
        W -= v.W;
        return *this;
    }
    template <class T>
    Vec4<T> Vec4<T>::operator- (const Vec4<T> & v) const
    {
        Vec4 t = *this;
        t -= v;
        return t;
    }
    template <class T>
    Vec4<T> Vec4<T>::operator- (const T valeur)
    {
        X -= valeur;
        Y -= valeur;
        Z -= valeur;
        W -= valeur;
        return *this;
    }
    template <class T>
    Vec4<T> & Vec4<T>::operator*= (const T a)
    {
        X *= a;
        Y *= a;
        Z *= a;
        W *= a;
        return *this;
    }
    template <class T>
    Vec4<T> Vec4<T>::operator* (const T a)const
    {
        Vec4 t = *this;
        t *= a;
        return t;
    }
    template <class T>
    Vec4<T> operator* (const T a, const Vec4<T>& v)
    {
        return Vec4<T>(v.X*a, v.Y*a, v.Z*a, v.W*a);
    }
    template <class T>
    Vec4<T> & Vec4<T>::operator* (const Vec4<T> &v)
    {
        X *= v.X;
        Y *= v.Y;
        Z *= v.Z;
        W *= v.W;
        return *this;
    }
    template <class T>
    Vec4<T> & Vec4<T>::operator/= (const T a)
    {
        X /= a;
        Y /= a;
        Z /= a;
        W /= a;
        return *this;
    }
    template <class T>
    Vec4<T> Vec4<T>::operator/ (const T a)const
    {
        Vec4 t = *this;
        t /= a;
        return t;
    }
    template <class T>
    bool Vec4<T>::operator< (const Vec4<T> &v)
    {
        if(X < v.X && Y < v.Y && Z < v.Z && W < v.W)
            return true;
        return false;
    }
    template <class T>
    bool Vec4<T>::operator< (const T valeur)
    {
        if(X < valeur && Y < valeur && Z < valeur && W < valeur)
            return true;
        return false;
    }



    template <class T>
    bool Vec4<T>::operator> (const Vec4<T> &v)
    {
        if(X > v.X && Y > v.Y && Z > v.Z && W > v.W)
            return true;
        return false;
    }
    template <class T>
    bool Vec4<T>::operator> (const T valeur)
    {
        if(X > valeur && Y > valeur && Z > valeur && W > valeur)
            return true;
        return false;
    }



    template <class T>
    bool Vec4<T>::operator<= (const Vec4<T> &v)
    {
        if(X <= v.X && Y <= v.Y && Z <= v.Z && W <= v.W)
            return true;
        return false;
    }
    template <class T>
    bool Vec4<T>::operator<= (const T valeur)
    {
        if(X <= valeur && Y <= valeur && Z <= valeur && W <= valeur)
            return true;
        return false;
    }



    template <class T>
    bool Vec4<T>::operator>= (const Vec4<T> &v)
    {
        if(X >= v.X && Y >= v.Y && Z >= v.Z && W >= v.W)
            return true;
        return false;
    }
    template <class T>
    bool Vec4<T>::operator>= (const T valeur)
    {
        if(X >= valeur && Y >= valeur && Z >= valeur && W >= valeur)
            return true;
        return false;
    }


    template <class T>
    Vec4<T> Vec4<T>::crossProduct(const Vec4<T> & v)const
    {
        Vec4<T> t;
        t.X = Y*v.Z - Z*v.Y;
        t.Y = Z*v.X - X*v.Z;
        t.Z = X*v.Y - Y*v.X;
        t.W = 1;
        return t;
    }
    template <class T>
    double Vec4<T>::length()const
    {
        return sqrt(X*X + Y*Y + Z*Z + W*W);
    }
    template <class T>
    Vec4<T> & Vec4<T>::normalize()
    {
        (*this) /= length();
        return (*this);
    }
    template <class T>
    Vec4<T> Vec4<T>::COPY(const Vec4 &v)
    {
        X = v.X;
        Y = v.Y;
        Z = v.Z;
        W = v.W;
        return *this;
    }
    template <class T>
    Vec4<T> Vec4<T>::DirectCopy()
    {
        Vec4<T> cop;
        cop.X = X;
        cop.Y = Y;
        cop.Z = Z;
        cop.W = W;
        return cop;
    }
    template <class T>
    Vec4<T> Vec4<T>::SET(T x, T y, T z, T w)
    {
        X = x;
        Y = y;
        Z = z;
        W = w;
        return *this;
    }
    template <class T>
    std::ostream& operator<<(std::ostream& target, const Vec4<T>& source)
    {
        return target << source.X << ", " << source.Y << ", " << source.Z << ", " << source.W;
    }
    template <class T>
    Vec4<T> Vec4<T>::NEGATE()
    {
        X = -X;
        Y = -Y;
        Z = -Z;
        W = -W;
        return *this;
    }
    template <class T>
    Vec4<T> Vec4<T>::NEGATEprecisely(bool x, bool y, bool z, bool w)
    {
        if(x) X = -X;
        if(y) Y = -Y;
        if(z) Z = -Z;
        if(w) W = -W;
        return *this;
    }
    template <class T>
    double Vec4<T>::dot(Vec4<T> v)
    {
        return X * v.X + Y * v.Y + Z * v.Z + W * v.W;
    }
}
}

#endif // __cplusplus

#endif // VEC4_HPP
