//
// Created by mitom on 7/21/21.
//

#ifndef MATH_CALCULATE_H
#define MATH_CALCULATE_H

#include "defines.h"

MATH_NAMESPACE_BEGIN
MATH_CALCULATE_NAMESPACE_BEGIN

template <typename T>
void foreach_negate_value(T& value)
{
    value = -value;
}

template <typename T>
struct foreach_addition_const
{
    T value;
    foreach_addition_const(T const & value) : value(value){}
    void operator() (T& val){val += value; }
};

template <typename T>
struct foreach_substraction_const
{
    T value;
    foreach_substraction_const(T const & value) : value(value){}
    void operator() (T& val){val -= value; }
};

template <typename T>
struct foreach_multiply_const
{
    T value;
    foreach_multiply_const(T const & value) : value(value){}
    void operator() (T& val){val *= value; }
};

template <typename T>
struct foreach_divition_const
{
    T value;
    foreach_divition_const(T const & value) : value(value){}
    void operator() (T& val){val /= value; }
};



MATH_CALCULATE_NAMESPACE_END
MATH_NAMESPACE_END
#endif //MATH_CALCULATE_H