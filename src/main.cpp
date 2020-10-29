#include <iostream>

#include "Loader.h"

int main() {
    string dataPath = "../data/data.txt";
    std::cout << "Hello Linear Programming Solver!" << std::endl;
    Loader loader(dataPath);
    auto matrix = loader.getMatrix();
    return 0;
}
