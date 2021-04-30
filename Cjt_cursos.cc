/** @file Cjt_cursos.cc
    @brief Codi de la classe Cjt_cursos
*/

#include "Cjt_cursos.hh"

Cjt_cursos::Cjt_cursos() {}

/*int Cjt_cursos::cerca_dicot(const vector<Curs>& vcurs, int left, int right, int c) {
  int i;
  
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }

  return i; 
  
}*/

void Cjt_cursos::sumar_usuari(int c) {
    vcurs[c-1].sumar_usuari();
}

bool Cjt_cursos::existeix_curs(int c) const {
    if (c > 0 and c <= vcurs.size()) return true;
    else return false;
}

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

void Cjt_cursos::escriure_curs(int c) const {
    cout << c << ' ';
    vcurs[c-1].escriure();
}
