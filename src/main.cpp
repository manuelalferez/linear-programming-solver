#include <iostream>

#include "Loader.h"
#include "Solver.h"

int main() {
    string dataPath = "../data/data.txt";
    std::cout << "Hello Linear Programming Solver!" << std::endl;
    Loader loader(dataPath);
    vector<string> *names_of_unknowns = loader.getNamesOfUnknowns();
    Solver solver(loader.getMatrix(), loader.getNoNegativityConditions());
    vector<float> solution = solver.calculateSolution();
    cout << "Solution: " << endl;
    for (int i = 0; i < solution.size(); ++i) {
        cout << names_of_unknowns->at(i) << "= " << solution.at(i) << " " << endl;
    }
    return 0;
}
