#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

int main() {
    cout << "Welcome to the C++ CMake Project!" << endl;
    
    printHello();

    cout << "adding 5 + 3: " << add(5,3) << endl;

    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {1, 4, 9, 16, 25};

    plot(x, y);
    
    return 0;
}