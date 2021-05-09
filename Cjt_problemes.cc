/** @file Cjt_problemes.cc
    @brief Codi de la classe Cjt_problemes
*/

#include "Cjt_problemes.hh"  

Cjt_problemes::Cjt_problemes() {}

bool Cjt_problemes::ordre(const pair<string, Problema>& a, const pair<string, Problema>& b) {
    if (a.second.consultar_ratio() != b.second.consultar_ratio()) return a.second.consultar_ratio() < b.second.consultar_ratio();
    else return a.first < b.first;
}

void Cjt_problemes::nou_problema(string p) {
    mp[p];
    cout << mp.size() << endl;
}

void Cjt_problemes::actualitzar_pr(string p, int r) {
    map<string, Problema>::iterator it = mp.find(p);
    it -> second.actualitzar(r);
}

bool Cjt_problemes::existeix_problema(string p) const {
    map<string, Problema>::const_iterator it = mp.find(p);
    if (it != mp.end()) return true;
    else return false;
}


void Cjt_problemes::llegir_problemes() {
    int n;
    cin >> n;
    string p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        mp[p];
    }
}

void Cjt_problemes::llistar_problemes() const {
    map<string, Problema>::const_iterator it = mp.begin();
    vector<pair<string, Problema>> vp;
    while (it != mp.end()) {
        vp.push_back(make_pair(it -> first, it -> second)); 
        ++it;
    }  
    sort (vp.begin(), vp.end(), ordre);
    for (int i = 0; i < vp.size(); ++i) {
        cout << vp[i].first;
        vp[i].second.escriure();
    }
}

void Cjt_problemes::escriure_problema(string p) const {
    cout << p;
    map<string, Problema>::const_iterator it = mp.find(p);
    it -> second.escriure();   
}