#include <iostream>

#include "Problem.h"

int main() {
    string dataPath = "../data/data.txt";
    std::cout << "Hello Linear Programming Solver!" << std::endl;
    Problem problem(dataPath);
    return 0;
}
