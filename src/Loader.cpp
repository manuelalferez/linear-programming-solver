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
            cout << line << endl;

            string term;
            float coefficient;
            do {
                getline(ss, term, ';');
                coefficient = stof(term);
                this->_objective_function.push_back(coefficient);
            } while (!ss.eof());

            getline(fe, line);
            term = line.substr(line.find(';') + 1);
            int n_structural_conditions = stoi(term);
            this->_structural_conditions.resize(n_structural_conditions);
            skip(fe, 1, '\n');
            int n_slack_variables = 0;
            for (int i = 0; i < n_structural_conditions; ++i) {
                getline(fe, line);
                ss.clear();
                ss << line;
                do {
                    getline(ss, term, ';');
                    if (term == "<=") {
                        for (int j = 0; j < n_slack_variables; ++j) {
                            this->_structural_conditions.at(i).push_back(0);
                        }
                        n_slack_variables++;
                        coefficient = 1;
                    } else if (term == ">=") {
                        for (int j = 0; j < n_slack_variables; ++j) {
                            this->_structural_conditions.at(i).push_back(0);
                        }
                        n_slack_variables++;
                        coefficient = -1;
                    } else {
                        coefficient = stof(term);
                    }
                    this->_structural_conditions.at(i).push_back(coefficient);
                } while (!ss.eof());
            }
            getline(fe, line);
            term = line.substr(line.find(';') + 1);
            int n_non_negativity_conditions = stoi(term);
            this->_non_negativity_conditions.resize(n_non_negativity_conditions);
            skip(fe, 1, '\n');
            for (int i = 0; i < n_non_negativity_conditions; ++i) {
                getline(fe, line);
                ss.clear();
                ss << line;
                do {
                    getline(ss, term, ';');
                    this->_non_negativity_conditions.at(i).push_back(term);
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