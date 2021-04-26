/** @file Cjt_problemes.cc
    @brief Codi de la classe Cjt_problemes
*/

#include "Cjt_problemes.hh"    

void Cjt_problemes::llegir_problemes() {
    int n;
    cin >> n;
    string p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        mp[p];
    }
}

bool Cjt_problemes::existeix_problema(string p) const {
    map<string, Problema>::const_iterator it = mp.find(p);
    if (it != mp.end()) return true;
    else return false;
}


void Cjt_problemes::nou_problema(string p) {
    mp[p];
}

void Cjt_problemes::llistar_problemes() const {
    map<string, Problema>::const_iterator it = mp.begin();
    while (it != mp.end()) {
        cout << it -> first;
        escriure_problema(it -> second);
    }
}

void Cjt_problemes::escriure_problema(string p) const {
    escriure_problema(
    map<string, Problema>::const_iterator it = mp.begin()
