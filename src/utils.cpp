#include "utils.h"
#include <iostream>

#ifdef _DEBUG
#undef _DEBUG
#include "matplotlibcpp.h"
#define _DEBUG
#else
#include "matplotlibcpp.h"
#endif

namespace plt = matplotlibcpp;

void printHello() {
    std::cout << "Hello, World!" << std::endl;
}

int add(int a, int b) {
    return a + b;
}

void plot(std::vector<double> x, std::vector<double> y){    
    plt::plot(x, y);
    plt::show();
}