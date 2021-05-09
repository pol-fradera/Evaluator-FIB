/** @file Curs.cc
    @brief Codi de la classe Curs
*/

#include "Curs.hh"

Curs::Curs() {
    us_comp = us_ins = 0;
}

bool Curs::nou_curs(int n, const Cjt_sessions& se) {
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    bool correcte = true;
    int i = 0;
    while (correcte and i < n) {
        int j = i + 1;
        while (correcte and j < n) {
            if (se.interseccio(vs[i], vs[j])) correcte = false; 
            ++j;
        }
        ++i;
    }
    return correcte;
}

void Curs::sumar_usuari() {
    ++us_ins;
    cout << us_ins << endl;
}

void Curs::restar_usuari() {
    --us_ins;
}

void Curs::actualitzar_env(string p, string& p1, string& p2, const Cjt_sessions& se) {
    bool trobat = false;
    int i = 0;
    while (not trobat) {
        if (se.actualitzar_env(vs[i], p, p1, p2)) trobat = true;
        ++i;
    }
} 

int Curs::usuaris_inscrits() const {
    return us_ins;
}
/*
bool Curs::conte_problema(string p) const {
    bool trobat = false;
    for (int i = 0, i < vs.size(); ++i) {
        if (
}*/

void Curs::sessio_problema(string p, const Cjt_sessions& se) const {
    bool trobat = false;
    int i = 0;
    while (not trobat and i < vs.size()) {
        if (se.sessio_problema(vs[i], p)) trobat = true;
        ++i;
    }
    if (trobat) cout << vs[i-1] << endl;
    else cout << "error: el problema no pertenece al curso" << endl;
}

void Curs::problemes_env(vector<string>& vp, const Cjt_sessions& se) const {
    for (int i = 0; i < vs.size(); ++i) vp.push_back(se.problemes_env(vs[i]));
        
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
