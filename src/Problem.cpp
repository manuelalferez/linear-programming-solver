#include "Problem.h"

Problem::Problem(filePath) {
    ifstream fe;
    string line;

    fe.open(filePath);

    if (fe.good()) {
        while (!fe.eof()) {
            getline(fe, line);
            stringstream ss;
            ss << line;
            cout << line << endl;
//            getline(ss, dni, ';');
//            dlat = stold(latitud);
//            dlon = stold(longitud);
        }
        cout << "File charged successfully." << endl;
        fe.close();
    } else {
        cerr << "Cannot open file." << endl;
    }
}