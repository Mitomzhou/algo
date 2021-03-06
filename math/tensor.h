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

    Tensor<T,D+1,N,M> addLayer(Matrix<T,N,M> const& inlayer);

    template<int U>
    Tensor<T,D+U,N,M> addLayers(Tensor<T,U,N,M> const& inlayers);

    Matrix<T,N,M> operator[] (int index) const;


    void print();
    void shape();

    std::vector<Matrix<T,N,M>> getLayers() const;

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
        Matrix<T,N,M> mat(0);
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
Tensor<T,D+1,N,M> Tensor<T,D,N,M>::addLayer(Matrix<T,N,M> const& inlayer)
{
    Tensor<T,D+1,N,M> ret;
    for(int d=0; d<D+1; d++){
        if(d < D){
            ret.layers[d] = layers[d];
        }else {
            ret.layers[d] = inlayer;
        }
    }
    return ret;
}


template <typename T, int D, int N, int M>
template<int U>
Tensor<T,D+U,N,M> Tensor<T,D,N,M>::addLayers(Tensor<T,U,N,M> const& inlayers)
{
    Tensor<T,D+U,N,M> ret;
    for(int d=0; d<D+U; d++){
        if(d < D){
            ret.layers[d] = layers[d];
        }else {
            ret.layers[d] = inlayers[d-D];
        }
    }
    return ret;
}

template <typename T, int D, int N, int M>
Matrix<T,N,M> Tensor<T,D,N,M>::operator[] (int index) const
{
    return layers[index];
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

    template <typename T, int D, int N, int M>
    std::vector<Matrix<T,N,M>> Tensor<T,D,N,M>::getLayers() const
    {
        return this->layers;
    }


MATH_NAMESPACE_END

#endif //MATH_TENSOR_H
