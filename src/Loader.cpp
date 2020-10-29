#include "Loader.h"

Loader::Loader(string &pathFile) :
        _objective_function(),
        _non_negativity_conditions(),
        _structural_conditions() {
    ifstream fe;
    string line;

    fe.open(pathFile);

    if (fe.good()) {
        while (!fe.eof()) {
            skip(fe, 2, '\n');
            getline(fe, line);
            stringstream ss;
            ss << line;

            string term;
            float coefficient;
            do {
                getline(ss, term, ';');
                coefficient = stof(term);
                this->_objective_function.push_back(coefficient);
            } while (!ss.eof());
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