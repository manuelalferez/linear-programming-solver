#include <iostream>

#include "Loader.h"
#include "Problem.h"

int main() {
    string dataPath = "../data/data.txt";
    std::cout << "Hello Linear Programming Solver!" << std::endl;
    Loader loader(dataPath);
    Problem problem(loader.getMatrix());
    return 0;
}
