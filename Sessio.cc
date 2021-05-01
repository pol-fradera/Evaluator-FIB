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

void Sessio::llegir() {
    ap = llegir_bintree();
}

void Sessio::escriure() const {
    escriure_BinTree(ap);
    cout << endl;
}
