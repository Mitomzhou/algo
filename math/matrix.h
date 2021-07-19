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
    Matrix(void)
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


protected:
    T m[N * M];
};

template <typename T, int N, int M>
int constexpr Matrix<T,N,M>::rows;

template <typename T, int N, int M>
int constexpr Matrix<T,N,M>::cols;

// TODO 实现函数

MATH_NAMESPACE_END


#endif //MATH_MATRIX_H
