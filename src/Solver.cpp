#include <queue>
#include "Solver.h"

Solver::Solver(vector<vector<float>> *matrix, vector<vector<string>> *non_negativity_conditions) :
        _matrix(matrix),
        _non_negativity_conditions(non_negativity_conditions) {
}