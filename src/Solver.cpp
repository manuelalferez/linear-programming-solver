#include <queue>
#include "Solver.h"

Solver::Solver(vector<vector<float>> *matrix) :
        _matrix(matrix) {
    _number_of_unknowns = 0;
    for (int i = 0; i < this->_matrix->at(0).size(); ++i) {
        if (this->_matrix->at(0).at(i) != 0) {
            _number_of_unknowns++;
        } else {
            break;
        }
    }
    _solution = vector<float>(_number_of_unknowns);
}

vector<float> &Solver::calculateSolution() {
    cout << "Executing Solver." << endl;
    cout << "Initial Matrix: " << endl;
    printMatrix();
    while (!checkOptimality()) {
        int pivot_column = findPivotColumn();
        int pivot_row = findPivotRow(pivot_column);
        cout << "Pivot: [" << pivot_row << " , " << pivot_column << "]" << endl;
        gaussianElimination(pivot_row, pivot_column);
        printMatrix();
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

void Solver::gaussianElimination(int pivot_row, int pivot_column) {
    transformPivotToUnity(pivot_row, pivot_column);
    for (int row = 0; row < this->_matrix->size(); ++row) {
        if (row == pivot_row) {
            continue;
        } else {
            float scalar = -this->_matrix->at(row).at(pivot_column);
            for (int col = 0; col < this->_matrix->at(row).size(); ++col) {
                this->_matrix->at(row).at(col) =
                        scalar * this->_matrix->at(pivot_row).at(col) + this->_matrix->at(row).at(col);
            }
        }
    }
}

void Solver::transformPivotToUnity(int pivot_row, int pivot_column) {
    float pivot_value = this->_matrix->at(pivot_row).at(pivot_column);
    for (int col = 0; col < this->_matrix->at(0).size(); ++col) {
        this->_matrix->at(pivot_row).at(col) = this->_matrix->at(pivot_row).at(col) / pivot_value;
    }
}

void Solver::saveSolution() {
    int index_b = this->_matrix->at(0).size();
    for (int col = 0; col < _solution.size(); ++col) {
        for (int row = 0; row < this->_matrix->size(); ++row) {
            if (this->_matrix->at(row).at(col) == 1) {
                _solution.at(col) = this->_matrix->at(row).at(index_b - 1);
            }
        }
    }
}

void Solver::printMatrix() {
    for (int i = 0; i < this->_matrix->size(); ++i) {
        for (int j = 0; j < this->_matrix->at(i).size(); ++j) {
            cout << this->_matrix->at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

