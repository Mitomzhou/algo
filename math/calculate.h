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

//template <typename T>
//void foreach_negate_value(T& value)
//{
//    value = -value;
//}



MATH_CALCULATE_NAMESPACE_END
MATH_NAMESPACE_END
#endif //MATH_CALCULATE_H