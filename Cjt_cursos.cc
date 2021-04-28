/** @file Cjt_cursos.cc
    @brief Codi de la classe Cjt_cursos
*/

#include "Cjt_cursos.hh"

Cjt_cursos::Cjt_cursos() {}

void Cjt_cursos::llegir_cursos() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        Curs c;
        c.llegir(m);
        vcurs.push_back(c);
    }
}

void Cjt_cursos::llistar_cursos() const {
    int mida = vcurs.size();
    for (int i = 0; i <  mida; ++i) {
        cout << i+1 << ' ';
        vcurs[i].escriure();
    }
}
