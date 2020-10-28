#ifndef LINEAR_PROGRAMMING_SOLVER_PROBLEM_H
#define LINEAR_PROGRAMMING_SOLVER_PROBLEM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Problem {
public:
    Problem(string &filePath);

private:
    vector<vector<float>> matrix;
    vector<float> solution;
};

#endif //LINEAR_PROGRAMMING_SOLVER_PROBLEM_H
