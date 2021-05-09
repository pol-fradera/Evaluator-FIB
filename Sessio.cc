/** @file Sessio.cc
    @brief Codi de la classe Sessio
*/

#include "Sessio.hh"

Sessio::Sessio() {  
    num_prob = 0;
}


BinTree<string> Sessio::llegir_bintree() {
  string s;
  cin >> s;
  if (s == "0") return BinTree<string> ();
  sp.insert(s);
  ++num_prob;  
  return BinTree<string> (s, llegir_bintree(), llegir_bintree());
}


void Sessio::escriure_BinTree(const BinTree<string> &a)
{
    if (not a.empty()) {
        string x = a.value();
        cout << '(';
        escriure_BinTree(a.right());
        escriure_BinTree(a.left()); 
        cout << x << ')';
    }
}

void Sessio::actualitzar_map(string s, const BinTree<string> &a1, const BinTree<string> &a2) {
    string s1, s2;
    if (a1.empty()) s1 = "0";
    else s1 = a1.value();
    if (a2.empty()) s2 = "0";
    else s2 = a2.value();
    mp[s] = make_pair(s1, s2);
}

void Sessio::recorrer_arbre(const BinTree<string> &a) {
    if (not a.empty()) {
        actualitzar_map(a.value(), a.left(), a.right());
        recorrer_arbre(a.left());
        recorrer_arbre(a.right());
    }
}

bool Sessio::actualitzar_env(string p, string& p1, string& p2) {
    map<string, pair<string, string>>::const_iterator it = mp.find(p);
    if (it == mp.end()) return false;
    else {
        p1 = it -> second.first;
        p2 = it -> second.second;
    }
}

int Sessio::mida() const {
    return num_prob;
}

bool Sessio::conte_problema(string p) const {
    set<string>::const_iterator it = sp.find(p);
    if (it != sp.end()) return true;
    else return false;
}

string Sessio::problemes_env() const {
    return ap.value();
}

bool Sessio::interseccio(const Sessio& s2) const {
    set<string>::const_iterator it = sp.begin();
    bool trobat = false;
    while (not trobat and it != sp.end()){
        if (s2.conte_problema(*it)) trobat = true;
        else ++it;
    }
    return trobat;
}

void Sessio::llegir() {
    ap = llegir_bintree();
    recorrer_arbre(ap);
}

void Sessio::escriure() const {
    escriure_BinTree(ap);
    cout << endl;
}
