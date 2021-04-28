/** @file Problema.cc
    @brief Codi de la classe Problema
*/

#include "Problema.hh"


Problema::Problema(){
    t = 0;  //enviaments totals
    e = 0; //enviaments amb èxit
    ratio = 1;
}

void Problema::escriure() const {
    cout << '(' << t << ',' << e << ',' << ratio << ')' << endl;
}
