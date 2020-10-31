#ifndef LINEAR_PROGRAMMING_SOLVER_LOADER_H
#define LINEAR_PROGRAMMING_SOLVER_LOADER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <climits>

using namespace std;

class Loader {
public:
    explicit Loader(string &pathFile);

    vector<vector<float>> *getMatrix();

    vector<vector<string>> *getNoNegativityConditions();
    vector<string>* getNamesOfUnknowns();
private:
    int largestColumn();

    static void skip(std::istream &is, size_t n, char delimiter);

    static int getQuantityFunctions(ifstream &fe);

private:
    vector<float> _objective_function;
    vector<vector<float>> _structural_conditions;
    vector<vector<string>> _non_negativity_conditions;
    vector<string> _names_of_unknowns;
};

#endif //LINEAR_PROGRAMMING_SOLVER_LOADER_H
