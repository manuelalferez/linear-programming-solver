#include <iostream>

#include "Loader.h"
#include "Solver.h"

int main() {
    string dataPath = "../data/data.txt";
    std::cout << "Hello Linear Programming Solver!" << std::endl;
    Loader loader(dataPath);
    Solver solver(loader.getMatrix(), loader.getNoNegativityConditions());
    vector<float> solution = solver.calculateSolution();
    cout << "Solution: " << endl;
    for (float sol : solution) {
        cout << sol << " " << endl;
    }
    return 0;
}
