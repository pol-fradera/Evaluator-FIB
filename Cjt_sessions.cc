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

bool Cjt_sessions::actualitzar_env(string s, string p, string& p1, string& p2) {
    map<string, Sessio>::const_iterator it = ms.find(s);
    if (it -> second.actualitzar_env(p, p1, p2) return true;
    else return false;
}

bool Cjt_sessions::existeix_sessio(string s) const {
    map<string, Sessio>::const_iterator it = ms.find(s);
    if (it != ms.end()) return true;
    else return false;
}

bool Cjt_sessions::sessio_problema(string s, string p) const {
    map<string, Sessio>::const_iterator it = ms.find(s);
    if (it -> second.conte_problema(p)) return true;
    else return false;
}

string Cjt_sessions::problemes_env(string s) const {
    map<string, Sessio>::const_iterator it = ms.find(s);
    return it -> second.problemes_env();
}

bool Cjt_sessions::interseccio(string s1, string s2) const {
    map<string, Sessio>::const_iterator it1 = ms.find(s1);
    map<string, Sessio>::const_iterator it2 = ms.find(s2);
    if (it1 -> second.interseccio(it2 -> second)) return true;
    else return false;
}

void Cjt_sessions::llegir_sessions() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        Sessio se;
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


