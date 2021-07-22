#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

/**
 * 测试Vector.h
 */
void test_Vector()
{
    math::Vector<int, 5> ve;
    for(int i=0; i<ve.dim; i++){
        ve[i] = i+1;
    }

    std::cout << ve.sum() << std::endl;
    std::cout << ve.maximum() << std::endl;
    std::cout << ve.minimum() << std::endl;
    std::cout << ve.product() << std::endl;

    math::Vector<int, 5> ve2;
    for(int i=0; i<ve.dim; i++){
        ve2[i] = (i+1)*2;
    }

    math::Vector<int, 5> ve3(ve2);
    std::cout << ve3(2) << std::endl;
    ve3.print();

    math::Vector<int, 5> ve4(2);
    ve4.print();
    ve4.fill(1);
    ve4[2] = 10;
    ve3.print();
    ve4.print();
    std::cout << ve3.dot(ve4) << std::endl;
}

void test_Matrix()
{
    math::Matrix<int, 3,4> mat;
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            mat(i, j) = i*mat.cols + j;
        }
    }
    mat.print();
    math::Matrix<int, 4,2> mat1;
    for (int i = 0; i < mat1.rows; ++i) {
        for (int j = 0; j < mat1.cols; ++j) {
            mat1(i, j) = (i*mat1.cols + j) * 10;
        }
    }

    math::Matrix<int, 3,2> mat2 = mat.mult(mat1);
    mat2.print();
    math::Vector<int, 2> v1(2);
    mat2.mult(v1);
    mat2.negate();
    mat2 += 1;
    mat2.print();
    math::Matrix<int, 3,2> mat3 = mat2 + 1;
    mat2.print();
    mat3.print();
    mat3 /= 10;
    mat3.print();

    math::Matrix<int, 3,3> mat4 = mat3.hstack(mat3.col(0));
    mat4.print();

    mat.print();
    mat.delete_row(0).print();
    mat.delete_col(3).print();


}


int main() {
    std::cout << "Hello, World!" << std::endl;
//    test_Vector();
    test_Matrix();


    return 0;
}
