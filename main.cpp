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
    math::Matrix<int, 4,2> mat1(2);
    mat1.print();

//    math::Matrix<int, 3,2> mat2 = mat.mult(mat1);
//    mat2.print();
}



int main() {
    std::cout << "Hello, World!" << std::endl;
//    test_Vector();
    test_Matrix();


    return 0;
}
