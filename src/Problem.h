#ifndef LINEAR_PROGRAMMING_SOLVER_PROBLEM_H
#define LINEAR_PROGRAMMING_SOLVER_PROBLEM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Problem {
public:
    Problem(vector<vector<float>> *matrix);

private:
    vector<vector<float>> *_matrix;
    vector<float> _solution;
};

#endif //LINEAR_PROGRAMMING_SOLVER_PROBLEM_H
