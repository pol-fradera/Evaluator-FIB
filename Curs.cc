/** @file Curs.cc
    @brief Codi de la classe Curs
*/

#include "Curs.hh"

Curs::Curs() {
    us_comp = us_ins = 0;
}

void Curs::llegir(int m) {
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
}

void Curs::escriure() const {
    cout << us_comp << ' ' << us_ins << ' ' << vs.size() << " (";
    for (int i = 0; i < vs.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << vs[i];
    }
    cout << ')' << endl;
    /*
    list<string>::const_iterator it = lc.begin();
    while (it != lc.end()) {
        if (it != lc.begin()) cout << ' ';
        cout << *it;
        ++it;
    }
    cout << ')' << endl;
    */
}
