#include "Loader.h"

Loader::Loader(string &pathFile) :
        _objective_function(),
        _non_negativity_conditions(),
        _structural_conditions(),
        _names_of_unknowns() {
    ifstream fe;
    string line;

    fe.open(pathFile);

    if (fe.good()) {
        while (!fe.eof()) {
            skip(fe, 1, '\n');
            getline(fe, line);
            stringstream ss;
            ss << line;

            string term;
            float coefficient;

            do {
                getline(ss, term, ';');
                this->_names_of_unknowns.push_back(term);
            } while (!ss.eof());

            getline(fe, line);
            ss.clear();
            ss << line;

            do {
                getline(ss, term, ';');
                coefficient = stof(term);
                this->_objective_function.push_back(coefficient);
            } while (!ss.eof());

            for (int i = 1; i < this->_objective_function.size(); ++i) {
                this->_objective_function.at(i) = -this->_objective_function.at(i);
            }

            this->_structural_conditions.resize(getQuantityFunctions(fe));
            skip(fe, 1, '\n');
            int n_slack_variables = 0;
            for (auto &_structural_condition : this->_structural_conditions) {
                getline(fe, line);
                ss.clear();
                ss << line;
                do {
                    getline(ss, term, ';');
                    if (term == "<=") {
                        for (int j = 0; j < n_slack_variables; ++j) {
                            _structural_condition.push_back(0);
                        }
                        n_slack_variables++;
                        coefficient = 1;
                    } else if (term == ">=") {
                        for (int j = 0; j < n_slack_variables; ++j) {
                            _structural_condition.push_back(0);
                        }
                        n_slack_variables++;
                        coefficient = -1;
                    } else {
                        coefficient = stof(term);
                    }
                    _structural_condition.push_back(coefficient);
                } while (!ss.eof());
            }

            this->_non_negativity_conditions.resize(getQuantityFunctions(fe));
            skip(fe, 1, '\n');
            for (auto &_non_negativity_condition : this->_non_negativity_conditions) {
                getline(fe, line);
                ss.clear();
                ss << line;
                do {
                    getline(ss, term, ';');
                    _non_negativity_condition.push_back(term);
                } while (!ss.eof());
            }
        }
        cout << "File charged successfully." << endl;
        fe.close();
    } else {
        cerr << "Cannot open file." << endl;
    }
}

void Loader::skip(istream &is, size_t n, char delimiter) {
    size_t i = 0;
    while (i++ < n)
        is.ignore(80, delimiter);
}

int Loader::getQuantityFunctions(ifstream &fe) {
    string line;
    getline(fe, line);
    string num_functions = line.substr(line.find(';') + 1);
    return stoi(num_functions);
}

vector<vector<float>> *Loader::getMatrix() {
    int n_columns = largestColumn() + 1;
    int n_rows = 1 + this->_structural_conditions.size();
    vector<vector<float>> *matrix = new vector<vector<float>>(n_rows, vector<float>(n_columns, 0));
    for (int i = 0; i < this->_objective_function.size(); ++i) {
        matrix->at(0).at(i) = this->_objective_function[i];
    }
    for (int j = 0; j < this->_structural_conditions.size(); ++j) {
        for (int i = 0; i < this->_structural_conditions.at(j).size() - 1; ++i) {
            matrix->at(j + 1).at(i + 1) = this->_structural_conditions[j][i];
        }
        matrix->at(j + 1).at(n_columns - 1) = this->_structural_conditions[j].back();
    }
    return matrix;
}

int Loader::largestColumn() {
    int max = 0;
    for (auto &_structural_condition : this->_structural_conditions) {
        if (max < _structural_condition.size())
            max = _structural_condition.size();
    }
    return max;
}

vector<vector<string>> *Loader::getNoNegativityConditions() {
    return &this->_non_negativity_conditions;
}

vector<string> *Loader::getNamesOfUnknowns() {
    return &this->_names_of_unknowns;
}
