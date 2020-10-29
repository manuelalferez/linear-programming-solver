#ifndef LINEAR_PROGRAMMING_SOLVER_SOLVER_H
#define LINEAR_PROGRAMMING_SOLVER_SOLVER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solver {
public:
    Solver(vector<vector<float>> *matrix, vector<vector<string>> *non_negativity_conditions);

private:
    vector<vector<float>> *_matrix;
    vector<vector<string>> *_non_negativity_conditions;
    vector<float> _solution;
};

#endif //LINEAR_PROGRAMMING_SOLVER_SOLVER_H
