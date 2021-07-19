//
// Created by Administrator on 2021/7/16.
//

#ifndef MATH_VERTOR_H
#define MATH_VERTOR_H

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

#include "defines.h"


MATH_NAMESPACE_BEGIN

/**
 * Vector type
 */
template <typename T, int N> class Vector;
typedef Vector<float, 1> Vec1f;
typedef Vector<float, 2> Vec2f;
typedef Vector<float, 3> Vec3f;
typedef Vector<double, 1> Vec1d;
typedef Vector<double, 2> Vec2d;
typedef Vector<double, 3> Vec3d;
typedef Vector<int, 1> Vec1i;
typedef Vector<int, 2> Vec2i;
typedef Vector<int, 3> Vec3i;
typedef Vector<std::size_t,1> Vec1st;
typedef Vector<std::size_t,2> Vec2st;
typedef Vector<std::size_t,3> Vec3st;
typedef Vector<char,1> Vec1c;
typedef Vector<char,2> Vec2c;
typedef Vector<char,3> Vec3c;

template <typename T, int N>
class Vector
{
public:
    typedef T ValueType;

    static int constexpr dim = N;

    /* 构造函数*/
    Vector(void);
    explicit Vector (T const* values);
    explicit Vector (T const& values);

    /* 填充值*/
    Vector<T,N>& fill (T const& value);
    /* copy值*/
    Vector<T,N>& copy (T const* values, int num = N);
    /* 最小值*/
    T minimum(void) const;
    /* 最大值*/
    T maximum(void) const;
    /* 求和*/
    T sum(void) const;
    /* 点积*/
    T product(void) const;

    /** 对象操作 */
    T& operator[] (int index);
    T const& operator[] (int index) const;
    T& operator() (int index);
    T const& operator() (int index) const;

protected:
    T v[N];

};


template <typename T, int N>
int constexpr Vector<T,N>::dim;

template <typename T, int N>
inline
Vector<T, N>::Vector(void)
{
}

template <typename T, int N>
inline
Vector<T, N>::Vector(T const* values)
{
    std::copy(values, values + N, v);
}

template <typename T, int N>
inline
Vector<T,N>::Vector (T const& value)
{
    fill(value);
}

template <typename T, int N>
inline
Vector<T,N>& Vector<T,N>::fill (T const& value)
{
    std::fill(v, v + N, value);
    return *this;
}

template <typename T, int N>
inline
Vector<T,N>& Vector<T,N>::copy (T const* values, int num)
{
    std::copy(values, values + num, this->v);
    return *this;
}

template <typename T, int N>
inline
T Vector<T,N>::minimum() const
{
    return *std::min_element(v, v + N);
}

template <typename T, int N>
inline
T Vector<T,N>::maximum() const
{
    return *std::max_element(v, v + N);
}

template <typename T, int N>
inline
T Vector<T,N>::sum(void) const
{
    return std::accumulate(v, v + N, T(0), std::plus<T>());
}

template <typename T, int N>
inline
T Vector<T,N>::product(void) const
{
    return std::accumulate(v, v + N, T(1), std::multiplies<T>());
}


template <typename T, int N>
inline
T& Vector<T,N>::operator[] (int index)
{
    return v[index];
}

template <typename T, int N>
inline
T const& Vector<T,N>::operator[] (int index) const
{
    return v[index];
}

template <typename T, int N>
inline
T& Vector<T,N>::operator() (int index)
{
    return v[index];
}

template <typename T, int N>
inline
T const& Vector<T,N>::operator() (int index) const
{
    return v[index];
}


MATH_NAMESPACE_END

#endif //MATH_VERTOR_H
