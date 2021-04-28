/** @file Sessio.cc
    @brief Codi de la classe Sessio
*/

#include "Sessio.hh"

Sessio::Sessio() {  }

int Sessio::size(const BinTree<string>& a) {
    if (a.empty()) return 0;
    else return 1 + size(a.left()) + size(a.right());
}

BinTree<string> Sessio::llegir_bintree() {
  string s;
  cin >> s;
  if (s == "0") return BinTree<string> ();
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
    return size(ap);
}

void Sessio::llegir() {
    ap = llegir_bintree();
}

void Sessio::escriure() const {
    escriure_BinTree(ap);
    cout << endl;
}
