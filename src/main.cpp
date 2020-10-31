#include <iostream>

#include "Loader.h"
#include "Solver.h"

int main() {
    string dataPath = "../data/data.txt";
    std::cout << "Hello Linear Programming Solver!" << std::endl;
    Loader loader(dataPath);
    Solver solver(loader.getMatrix(), loader.getNoNegativityConditions());
    solver.calculateSolution();
    return 0;
}
