/** @file Usuari.cc
    @brief Codi de la classe Usuari
*/

#include "Usuari.hh"

Usuari::Usuari() {
    env_tot = pr_res = pr_int = id_curs = 0;
}

void Usuari::inscriure(int c) {
    id_curs = c; //en el vector (c-1)
}

bool Usuari::esta_inscrit() const {
    if (id_curs == 0) return false;
    else return true;
}

void Usuari::consulta_curs() const {
    cout << id_curs << endl;
}

void Usuari::escriure() const {
    cout << '(' << env_tot << ',' << pr_res << ',' << pr_int << ',' << id_curs << ')' << endl;
}
