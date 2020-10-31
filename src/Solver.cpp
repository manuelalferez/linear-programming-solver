#include <queue>
#include "Solver.h"

Solver::Solver(vector<vector<float>> *matrix, vector<vector<string>> *non_negativity_conditions) :
        _matrix(matrix),
        _non_negativity_conditions(non_negativity_conditions) {
}

vector<float> &Solver::calculateSolution() {
    while (!checkOptimality()) {
        int pivot_column = findPivotColumn();
        int pivot_row = findPivotRow(pivot_column);
        doPivoting(pivot_row, pivot_column);
    }
    saveSolution();
    return this->_solution;
}

bool Solver::checkOptimality() {
    int positive_values = 0;
    for (int i = 1; i < this->_matrix->at(0).size(); ++i) {
        if (this->_matrix->at(0).at(i) >= 0) {
            positive_values++;
        }
    }
    return this->_matrix->at(0).size() - 1 == positive_values;
}

int Solver::findPivotColumn() {
    int pivot_column = 0, min_value = INT_MAX;
    for (int i = 1; i < this->_matrix->at(0).size(); ++i) {
        if (this->_matrix->at(0).at(i) < min_value) {
            pivot_column = i;
            min_value = this->_matrix->at(0).at(i);
        }
    }
    return pivot_column;
}

int Solver::findPivotRow(int pivot_column) {
    int pivot_row = 0, min_value = INT_MAX;
    int index_b = this->_matrix->at(0).size();
    for (int i = 1; i < this->_matrix->size(); ++i) {
        if (this->_matrix->at(i).at(pivot_column) > 0) {
            int b_div_i = this->_matrix->at(i).at(index_b - 1) / this->_matrix->at(i).at(pivot_column);
            if (b_div_i < min_value) {
                pivot_row = i;
                min_value = b_div_i;
            }
        }
    }
    return pivot_row;
}

void Solver::doPivoting(int pivotRow, int pivotColumn) {
    cout << "Doing pivoting" << endl;
}

void Solver::saveSolution() {
    cout << "Saving solution" << endl;
}

