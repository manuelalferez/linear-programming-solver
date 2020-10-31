#include <queue>
#include "Solver.h"

Solver::Solver(vector<vector<float>> *matrix, vector<vector<string>> *non_negativity_conditions) :
        _matrix(matrix),
        _non_negativity_conditions(non_negativity_conditions) {
}

vector<float> &Solver::calculateSolution() {
    while (!checkOptimality()) {
        int pivotColumn = findPivotColumn();
        int pivotRow = findPivotRow(pivotColumn);
        doPivoting(pivotRow, pivotColumn);
    }
    saveSolution();
    return this->_solution;
}

bool Solver::checkOptimality() {
    int positivesValues = 0;
    for (int i = 1; i < this->_matrix->at(0).size(); ++i) {
        if (this->_matrix->at(0).at(i) >= 0) {
            positivesValues++;
        }
    }
    return this->_matrix->at(0).size() - 1 == positivesValues;
}

int Solver::findPivotColumn() {
    return 0;
}

int Solver::findPivotRow(int pivotColumn) {
    return pivotColumn;
}

void Solver::doPivoting(int pivotRow, int pivotColumn) {
    cout << "Doing pivoting" << endl;
}

void Solver::saveSolution() {
    cout << "Saving solution" << endl;
}

