/** @file Sessio.cc
    @brief Codi de la classe Sessio
*/

#include "Sessio.hh"

BinTree<string> llegir_bintree() {
  string s;
  cin >> s;
  if (s == "0") return BinTree<string> ();
  return BinTree<string> (s, llegir_bintree(), llegir_bintree());
}

void Sessio::llegir_sessio() {
    ap = llegir_bintree();
}

void write_bintree_int(const BinTree<int> &a)
{
	if (not a.empty()) {
		int x = a.value();
        cout << '(';
		write_bintree_int(a.left()); 
		cout << " " << x << ')';
		write_bintree_int(a.right());
  }
}
