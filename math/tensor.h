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
#include <vector>

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
    Tensor (Tensor<T,D,N,M> const& other); // copy


    Tensor<T,D,N,M>& fill (T const& value);
    Matrix<T,N,M> layer (int index) const;



    void print();
    void shape();
protected:
    typedef std::vector<Matrix<T,N,M>> Layers;
    Layers layers;

};

template <typename T, int D, int N, int M>
int constexpr Tensor<T,D,N,M>::depths;

template <typename T, int D, int N, int M>
int constexpr Tensor<T,D,N,M>::rows;

template <typename T, int D, int N, int M>
int constexpr Tensor<T,D,N,M>::cols;


template <typename T, int D, int N, int M>
Tensor<T,D,N,M>::Tensor (void)
{
    for(int i=0; i<D; i++){
        Matrix<T,N,M> mat;
        layers.push_back(mat);
    }
}

template <typename T, int D, int N, int M>
Tensor<T,D,N,M>::Tensor (T const* values)
{
    // TODO
}

template <typename T, int D, int N, int M>
Tensor<T,D,N,M>::Tensor (T const& value)
{
    for (int d=0; d<D; d++){
        Matrix<T,N,M> mat(value);
        layers.push_back(mat);
    }
}

template <typename T, int D, int N, int M>
Tensor<T,D,N,M>::Tensor (Tensor<T,D,N,M> const& other)
{
    // TODO
}

template <typename T, int D, int N, int M>
Tensor<T,D,N,M>& Tensor<T,D,N,M>::fill (T const& value)
{
    for (int d=0; d<D; d++){
        this->layers[d].fill(value);
    }
    return *this;
}

template <typename T, int D, int N, int M>
Matrix<T,N,M> Tensor<T,D,N,M>::layer (int index) const
{
    return this->layers[index];
}

template <typename T, int D, int N, int M>
void Tensor<T,D,N,M>::print()
{
    std::cout << "tensor shape: (" << D << ", " << N << ", " << M << ")" << std::endl;
    std::cout << "----------------------" << std::endl;
    for (int d=0; d<D; d++){
        Matrix<T,N,M> mat = layers[d];
        mat.print();
    }
    std::cout << "----------------------" << std::endl;
}

template <typename T, int D, int N, int M>
void Tensor<T,D,N,M>::shape()
{
    std::cout << "tensor shape: (" << D << ", " << N << ", " << M << ")" << std::endl;
}

MATH_NAMESPACE_END

#endif //MATH_TENSOR_H
