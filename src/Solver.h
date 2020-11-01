#ifndef LINEAR_PROGRAMMING_SOLVER_SOLVER_H
#define LINEAR_PROGRAMMING_SOLVER_SOLVER_H

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solver {
public:
    Solver(vector<vector<float>> *matrix);

    vector<float> &calculateSolution();

private:
    bool checkOptimality();

    int findPivotColumn();

    int findPivotRow(int pivot_column);

    void gaussianElimination(int pivot_row, int pivot_column);

    void transformPivotToUnity(int pivot_row, int pivot_column);

    void saveSolution();

    void printMatrix();

private:
    vector<vector<float>> *_matrix;
    vector<float> _solution;
    int _number_of_unknowns;
};

#endif //LINEAR_PROGRAMMING_SOLVER_SOLVER_H
