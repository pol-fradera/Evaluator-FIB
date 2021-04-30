/** @file Cjt_sessions.cc
    @brief Codi de la classe Cjt_sessions
*/

#include "Cjt_sessions.hh"

Cjt_sessions::Cjt_sessions() {}


void Cjt_sessions::nova_sessio(string s) {
    Sessio se;
    se.llegir();
    ms[s] = se;
    cout << ms.size() << endl;
}

bool Cjt_sessions::existeix_sessio(string s) const {
    map<string, Sessio>::const_iterator it = ms.find(s);
    if (it != ms.end()) return true;
    else return false;
}

void Cjt_sessions::llegir_sessions() {
    int n;
    cin >> n;
    Sessio se;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        se.llegir();
        ms[s] = se;
    }
}

void Cjt_sessions::llistar_sessions() const{
    map<string, Sessio>::const_iterator it = ms.begin();
    while (it != ms.end()) {
        cout << it -> first;
        cout << ' ' << it -> second.mida() << ' ';
        it -> second.escriure();
        ++it;
    }
}

void Cjt_sessions::escriure_sessio(string s) const {
    map<string, Sessio>::const_iterator it = ms.find(s);
    cout << s << ' ' << it -> second.mida() << ' ';
    it -> second.escriure();
}    


