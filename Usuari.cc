/** @file Usuari.cc
    @brief Codi de la classe Usuari
*/

#include "Usuari.hh"

Usuari::Usuari() {
    env_tot = pr_res = pr_int = id_curs = 0;
}

void Usuari::inscriure(int c, const Cjt_cursos& cu, const Cjt_sessions& se) {
    id_curs = c; //en el vector (c-1)
    vector<string> vp;
    cu.problemes_env(c, vp, se);
    for (int i = 0; i < vp.size(); ++i) mpr_env[vp[i]];
}

void Usuari::enviament(string p, int r, const Cjt_cursos& cu, const Cjt_sessions& se) {
    ++env_tot;
    map<string, int>::const_iterator it = mpr_env.find(p);
    if (it -> second == 0) ++pr_int;
    if (r == 0) ++mpr_env[p];
    else {
        mpr_res[p] = it -> second + 1;
        mpr_env.erase(p);
        ++pr_res;
        string p1, p2;
        cu.actualitzar_env(id_curs, p, p1, p2, se);
        if (p1 != "0") mpr_env[p1];
        if (p2 != "0") mpr_env[p2];
    }
    
}

bool Usuari::esta_inscrit() const {
    if (id_curs == 0) return false;
    else return true;
}

int Usuari::consulta_curs() const {
    return id_curs;
}

void Usuari::problemes_res() const {
    map<string, int>::const_iterator it = mpr_res.begin();
    while (it != mpr_res.end()) {
        cout << it -> first << '(' << it -> second << ')' << endl;
        ++it;
    }
}

void Usuari::problemes_env() const {
    map<string, int>::const_iterator it = mpr_env.begin();
    while (it != mpr_env.end()) {
        cout << it -> first << '(' << it -> second << ')' << endl;
        ++it;
    }
}
/*
void Usuari::problemes_resolts() const {
    
}*/

void Usuari::escriure() const {
    cout << '(' << env_tot << ',' << pr_res << ',' << pr_int << ',' << id_curs << ')' << endl;
}
