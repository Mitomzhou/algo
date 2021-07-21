//
// Created by mitom on 2021/7/18.
//

#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <ostream>
#include <algorithm>

#include "defines.h"
#include "vector.h"
#include "calculate.h"

MATH_NAMESPACE_BEGIN

template <typename T, int N, int M> class Matrix;
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


template <typename T, int N, int M>
class Matrix {
public:
    typedef T ValueType;

    /* N行 M列 */
    static int constexpr rows = N;
    static int constexpr cols = M;

    /* 构造函数 *************************************/
    Matrix(void);
    explicit Matrix (T const* values);
    explicit Matrix (T const& value);
    Matrix (Matrix<T,N,M> const& other);  // copy

    /* 填充值 */
    Matrix<T,N,M>& fill (T const& value);
    /* 获取行和列 */
    Vector<T,M> row(int index) const;
    Vector<T,N> col(int index) const;

    /* 返回matrix最小值最大值 */
    T minimum (void) const;
    T maximum (void) const;

    /* 一元操作 *************************************/
    /* 取负 */
    Matrix<T,N,M>& negate (void);
    Matrix<T,N,M> negated (void) const;
    Matrix<T,M,N>& transpose (void);        // Transpose the current matrix
    Matrix<T,M,N> transposed (void) const;  // Returns a transposed copy

    /* 二元操作 ************************************/
    /* 矩阵乘矩阵 */
    template<int U>
    Matrix<T,N,U> mult (Matrix<T,M,U> const& rhs) const;
    /* 矩阵乘向量 */
    Vector<T,N> mult (Vector<T,M> const& rhs) const;

    /* 迭代器 ************************************/
    T* begin (void);
    T const* begin (void) const;
    T* end (void);
    T const* end (void) const;
    /* *操作，返回值 */
    T* operator* (void);
    T const* operator* (void) const;

    /* 对象操作 ************************************/
    /* 返回元素 */
    T& operator() (int row, int col);
    T const& operator() (int row, int col) const;
    /* 返回某行 */
    T& operator[] (unsigned int i);
    T const& operator[] (unsigned int i) const;
    /* 赋值操作 */
    Matrix<T,N,M>& operator= (Matrix<T,N,M> const& rhs);
    /* 取负操作 */
    Matrix<T,N,M> operator- (void) const;
    /* 加减乘矩阵 */
    Matrix<T,N,M>& operator+= (Matrix<T,N,M> const& rhs);
    Matrix<T,N,M> operator+ (Matrix<T,N,M> const& rhs) const;
    Matrix<T,N,M>& operator-= (Matrix<T,N,M> const& rhs);
    Matrix<T,N,M> operator- (Matrix<T,N,M> const& rhs) const;
    template <int U>
    Matrix<T,N,U> operator* (Matrix<T,M,U> const& rhs) const;
    Vector<T,N> operator* (Vector<T,M> const& rhs) const;
    /* 加减乘除常数 */
    Matrix<T,N,M>& operator+= (T const& rhs);
    Matrix<T,N,M> operator+ (T const& rhs) const;
    Matrix<T,N,M>& operator-= (T const& rhs);
    Matrix<T,N,M> operator- (T const& rhs) const;
    Matrix<T,N,M>& operator*= (T const& rhs);
    Matrix<T,N,M> operator* (T const& rhs) const;
    Matrix<T,N,M>& operator/= (T const& rhs);
    Matrix<T,N,M> operator/ (T const& rhs) const;

    void print();

protected:
    T m[N * M];
};

template <typename T, int N, int M>
int constexpr Matrix<T,N,M>::rows;

template <typename T, int N, int M>
int constexpr Matrix<T,N,M>::cols;

template <typename T, int N, int M>
Matrix<T,N,M>::Matrix (void)
{
}

template <typename T, int N, int M>
Matrix<T,N,M>::Matrix (T const* values)
{
    std::copy(values, values + N * M, m);
}

template <typename T, int N, int M>
Matrix<T,N,M>::Matrix (T const& value)
{
    fill(value);
}

template <typename T, int N, int M>
Matrix<T,N,M>::Matrix (Matrix<T,N,M> const& other)
{
    std::copy(*other, *other + M * N, m);
}

template <typename T, int N, int M>
Matrix<T,N,M>& Matrix<T,N,M>::fill (T const& value)
{
    // std::fill(m, m + N * M, value); // 这种方式结果不对
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            (*this)(i,j) = value;
        }
    }
    return *this;
}

template <typename T, int N, int M>
Vector<T,M> Matrix<T,N,M>::row(int index) const
{
    Vector<T,M> ret;
    for(int i=0; i<M; i++){
        ret[i] = (*this)(index, i);
    }
    return ret;
}

template <typename T, int N, int M>
Vector<T,N> Matrix<T,N,M>::col(int index) const
{
    Vector<T,N> ret;
    for(int i=0; i<N; i++){
        ret[i] = (*this)(i, index);
    }
    return ret;
}

template <typename T, int N, int M>
T Matrix<T,N,M>::minimum() const
{
    return *std::min_element(m, m + N*M);
}

template <typename T, int N, int M>
T Matrix<T,N,M>::maximum() const
{
    return *std::max_element(m, m + N*M);
}

template <typename T, int N, int M>
Matrix<T,N,M>& Matrix<T,N,M>::negate (void)
{
    std::for_each(m, m + N*M, &calculate::foreach_negate_value<T>);
    return *this;
}

template <typename T, int N, int M>
Matrix<T,N,M> Matrix<T,N,M>::negated (void) const
{
    return Matrix<T,N,M>(*this).negate();
}

template <typename T, int N, int M>
Matrix<T,M,N>& Matrix<T,N,M>::transpose (void)
{
    Matrix<T,M,N> ret;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            ret(j,i) = (*this)(i,j);
    return ret;
}

template <typename T, int N, int M>
Matrix<T,M,N> Matrix<T,N,M>::transposed (void) const
{
    Matrix<T,M,N> ret;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            ret(j,i) = (*this)(i,j);
    return ret;
}

template <typename T, int N, int M>
T* Matrix<T,N,M>::operator* (void)
{
    return m;
}

template <typename T, int N, int M>
T const* Matrix<T,N,M>::operator* (void) const
{
    return m;
}

template <typename T, int N, int M>
T& Matrix<T,N,M>::operator() (int row, int col)
{
    return m[row * M + col];
}

template <typename T, int N, int M>
T const& Matrix<T,N,M>::operator() (int row, int col) const
{
    return m[row * M + col];
}

template <typename T, int N, int M>
template<int U>
Matrix<T,N,U> Matrix<T,N,M>::mult (Matrix<T,M,U> const& rhs) const
{
    Matrix<T,N,U> ret;
    for(int i=0; i<ret.rows; i++){
        for(int j=0; j<ret.cols; j++){
            Vector<T, M> v1 = (*this).row(i);
            Vector<T, M> v2 = rhs.col(j);
            ret(i,j) = v1.dot(v2);
        }
    }
    return ret;
}

template <typename T, int N, int M>
Vector<T,N> Matrix<T,N,M>::mult (Vector<T,M> const& rhs) const
{
    Vector<T,N> ret;
    for (int i = 0; i < ret.dim; ++i) {
        Vector<T, M> lhs = (*this).row(i);
        ret[i] = lhs.dot(rhs);
    }
    return ret;
}

template <typename T, int N, int M>
T* Matrix<T,N,M>::begin()
{
    return m;
}

template <typename T, int N, int M>
T const* Matrix<T,N,M>::begin() const
{
    return m;
}

template <typename T, int N, int M>
T* Matrix<T,N,M>::end()
{
    return m + N * M;
}

template <typename T, int N, int M>
T const* Matrix<T,N,M>::end() const
{
    return m + N * M;
}

template <typename T, int N, int M>
Matrix<T,N,M>& Matrix<T,N,M>::operator= (Matrix<T,N,M> const& rhs)
{
    std::copy(*rhs, *rhs + N * M, m);
    return *this;
}

template <typename T, int N, int M>
Matrix<T,N,M> Matrix<T,N,M>::operator- (void) const
{
    return Matrix<T,N,M>(*this).negated();
}

template <typename T, int N, int M>
Matrix <T,N,M> & Matrix<T,N,M>::operator+= (Matrix<T,N,M> const& rhs)
{
    std::transform(m, m + N * M, *rhs, m, std::plus<T>());
    return *this;
}
template <typename T, int N, int M>
Matrix<T,N,M> Matrix<T,N,M>::operator+ (Matrix<T, N, M> const& rhs) const
{
    return Matrix<T,N,M>(*this) += rhs;
}

template <typename T, int N, int M>
Matrix <T,N,M> & Matrix<T,N,M>::operator-= (Matrix<T,N,M> const& rhs)
{
    std::transform(m, m + N * M, *rhs, m, std::minus<T>());
    return *this;
}

template <typename T, int N, int M>
Matrix<T,N,M> Matrix<T,N,M>::operator- (Matrix<T, N, M> const& rhs) const
{
    return Matrix<T,N,M>(*this) -= rhs;
}

template <typename T, int N, int M>
template <int U>
Matrix<T,N,U> Matrix<T,N,M>::operator* (Matrix<T,M,U> const& rhs) const
{
    return Matrix<T,N,M>::mult(rhs);
}

template <typename T, int N, int M>
Vector<T,N> Matrix<T,N,M>::operator* (Vector<T,M> const& rhs) const
{
    return Matrix<T,N,M>::mult(rhs);
}

    template <typename T, int N, int M>
    Matrix<T,N,M>& Matrix<T,N,M>::operator+= (T const& rhs)
    {
        //std::for_each(m, m + N*M, &calculate::)
    }


///* 加减乘除常数 */
//Matrix<T,N,M>& operator+= (T const& rhs);
//Matrix<T,N,M> operator+ (T const& rhs) const;
//Matrix<T,N,M>& operator-= (T const& rhs);
//Matrix<T,N,M> operator- (T const& rhs) const;
//Matrix<T,N,M>& operator*= (T const& rhs);
//Matrix<T,N,M> operator* (T const& rhs) const;
//Matrix<T,N,M>& operator/= (T const& rhs);
//Matrix<T,N,M> operator/ (T const& rhs) const;



template <typename T, int N, int M>
void Matrix<T,N,M>::print()
{
    std::cout << "matrix shape: (" << N <<", " << M <<")"<< std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

MATH_NAMESPACE_END


#endif //MATH_MATRIX_H
