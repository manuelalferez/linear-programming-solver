#include <iostream>

#include "Loader.h"
#include "Solver.h"

void writeSolutionToFile(string &pathFile, vector<float> *solution, vector<string> *names_of_unknowns) {
    ofstream file;
    file.open(pathFile);
    if (file.good()) {
        file << "Solution: " << endl;
        for (int i = 0; i < solution->size(); ++i) {
            file << names_of_unknowns->at(i) << "= " << solution->at(i) << " " << endl;
        }
    } else {
        cerr << "Cannot open file." << endl;
    }
}

int main() {
    string dataPath = "../data/data.txt";
    string solutionPath = "../solution/solution.txt";
    std::cout << "Hello Linear Programming Solver!" << std::endl;
    Loader loader(dataPath);
    vector<string> *names_of_unknowns = loader.getNamesOfUnknowns();
    Solver solver(loader.getMatrix());
    vector<float> solution = solver.calculateSolution();
    writeSolutionToFile(solutionPath, &solution, names_of_unknowns);
    cout << "Solution: " << endl;
    for (int i = 0; i < solution.size(); ++i) {
        cout << names_of_unknowns->at(i) << "= " << solution.at(i) << " " << endl;
    }
    return 0;
}
