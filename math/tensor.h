//
// Created by mitom on 2021/7/18.
//

#ifndef MATH_TENSOR_H
#define MATH_TENSOR_H

#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <ostream>
#include <algorithm>

#include "defines.h"
#include "vector.h"
#include "matrix.h"

MATH_NAMESPACE_BEGIN

template <typename T, int D, int N, int M> class Tensor;
typedef Matrix<float, 2, 2> Matrix2f;
typedef Matrix<float, 3, 3> Matrix3f;
typedef Matrix<float, 4, 4> Matrix4f;
typedef Matrix<double, 2, 2> Matrix2d;
typedef Matrix<double, 3, 3> Matrix3d;
typedef Matrix<double, 4, 4> Matrix4d;
typedef Matrix<int, 2, 2> Matrix2i;
typedef Matrix<int, 3, 3> Matrix3i;
typedef Matrix<int, 4, 4> Matrix4i;
typedef Matrix<unsigned int, 2, 2> Matrix2ui;
typedef Matrix<unsigned int, 3, 3> Matrix3ui;
typedef Matrix<unsigned int, 4, 4> Matrix4ui;


template <typename T, int D, int N, int M>
class Tensor
{
public:
    typedef T ValueType;

    static int constexpr depths = D; // 深度/通道
    static int constexpr rows = N;
    static int constexpr cols = M;

    Tensor (void);
    explicit Tensor (T const* values);
    explicit Tensor (T const& value);
    Tensor (Tensor<T,D,N,M> const& other);


    Tensor<T,D,N,M>& fill (T const& value);
    Matrix<T,N,M> layer (int index) const;
}



MATH_NAMESPACE_END

#endif //MATH_TENSOR_H
