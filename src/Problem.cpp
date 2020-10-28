#include "Problem.h"

Problem::Problem(string &filePath) {
    ifstream fe;
    string line;

    fe.open(filePath);

    if (fe.good()) {
        while (!fe.eof()) {
            getline(fe, line);
            stringstream ss;
            ss << line;
            cout << line << endl;
        }
        cout << "File charged successfully." << endl;
        fe.close();
    } else {
        cerr << "Cannot open file." << endl;
    }
}