/** @file Problema.cc
    @brief Codi de la classe Problema
*/

#include "Problema.hh"


Problema::Problema(){
    t = 0;  //enviaments totals
    e = 0; //enviaments amb èxit
    ratio = 1;
}

void Problema::actualitzar(int r) {
    ++t;
    if (r == 1) ++e;
    ratio = double(t+1)/double(e+1); 
}

int Problema::consultar_ratio() const {
    return ratio;
}

void Problema::escriure() const {
    cout << '(' << t << ',' << e << ',' << ratio << ')' << endl;
}