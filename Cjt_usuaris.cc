/** @file Cjt_usuaris.cc
    @brief Codi de la classe Cjt_usuaris
*/

#include "Cjt_usuaris.hh"

Cjt_usuaris::Cjt_usuaris() {}
 
void Cjt_usuaris::alta_usuari(string u) {
    mu[u];
    cout << mu.size() << endl;
}

void Cjt_usuaris::baixa_usuari(string u) {
    mu.erase(u);
    cout << mu.size() << endl;
}

void Cjt_usuaris::inscriure_curs(string u, int c, const Cjt_cursos& cu, const Cjt_sessions& se) {
    map<string, Usuari>::iterator it = mu.find(u);
    it -> second.inscriure(c, cu, se);
}

bool Cjt_usuaris::existeix_usuari(string u) const {
    map<string, Usuari>::const_iterator it = mu.find(u);
    if (it != mu.end()) return true;
    else return false;
} 

bool Cjt_usuaris::esta_inscrit_nc(string u) const {
    map<string, Usuari>::const_iterator it = mu.find(u);
    if (it -> second.esta_inscrit()) return true;
    else return false;
}

void Cjt_usuaris::curs_usuari(string u) const {
    map<string, Usuari>::const_iterator it = mu.find(u);
    it -> second.consulta_curs();
}

void Cjt_usuaris::problemes_enviables(string u) const {
    map<string, Usuari>::const_iterator it = mu.find(u);
    it -> second.problemes_env();
}


void Cjt_usuaris::llegir_usuaris() {
    int n;
    cin >> n;
    string p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        mu[p];
    }
}

void Cjt_usuaris::llistar_usuaris() const {
    map<string, Usuari>::const_iterator it = mu.begin();
    while (it != mu.end()) {
        cout << it -> first;
        it -> second.escriure();
        ++it;
    }
}

void Cjt_usuaris::escriure_usuari(string u) const {
    cout << u;
    map<string, Usuari>::const_iterator it = mu.find(u);
    it -> second.escriure();  
}
