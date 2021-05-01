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

void Cjt_cursos::restar_usuari(int c) {
    vcurs[c-1].restar_usuari();
}

bool Cjt_cursos::existeix_curs(int c) const {
    if (c > 0 and c <= vcurs.size()) return true;
    else return false;
}
/*
bool Cjt_cursos::pertany_curs(int c, string p) const {
    if (vcurs[c].conte_problema(p)) return true;
    else return false;
}*/

void Cjt_cursos::sessio_problema(int c, string p, const Cjt_sessions& se) const {
    vcurs[c-1].sessio_problema(p, se);
}

void Cjt_cursos::problemes_env(int c, vector<string>& vp, const Cjt_sessions& se) const {
    vcurs[c-1].problemes_env(vp, se);
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
