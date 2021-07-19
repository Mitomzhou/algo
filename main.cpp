#include <iostream>

#include "math/vector.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    math::Vector<int, 5> ve;
    for(int i=0; i<ve.dim; i++){
        ve[i] = i+1;
    }

    int sum = ve.sum();
    std::cout << sum << std::endl;

    return 0;
}
