/** @file Cjt_sessions.cc
    @brief Codi de la classe Cjt_sessions
*/

#include "Cjt_sessions.hh"

void Cjt_sessions::llegir_sessions() {
    int n;
    cin >> n;
    string s;
    Sessio se;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ms[s] = se.llegir_sessio;
    }
}

bool Cjt_sessions::existeix_sessio(string s) {
    map<string, Sessio>::const_iterator it = ms.find(p);
    if (it != ms.end()) return true;
    else return false;
}

void Cjt_sessions::nova_sessio(string s) {
    Sessio se;
    ms[s] = se.llegir_sessio;
}


void Cjt_sessions::llistar_sessions() const {
    map<string, Sessio>::const_iterator it = ms.begin();
    while (it != ms.end()) {
        escriure_sessio(*it);
    }
}


