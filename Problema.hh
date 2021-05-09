/** @file Problema.hh
    @brief Especificació de la classe Problema
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

using namespace std;

#ifndef NO_DIAGRAM 
#include <string>
#include <iostream>
#endif

/** @class Problema
    @brief Representa les característiques d'un problema. 
*/
class Problema {

private:
    
  int t, e;
  double ratio;
  
public:
  
  //Constructores
    
  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un problema.
      \pre <em>cert</em>
      \post El resultat és un problema buit.
  */
  Problema();
  
  /** @brief Creadora amb paràmetre. 
      \pre <em>cert</em>
      \post El resultat és un problema amb identificador p.
  */
  Problema(string p);


  //Modificadores

  void actualitzar(int r);
 
  //Consultores

  /** @brief Consulta el nombre d'enviaments totals. 
      \pre <em>cert</em>
      \post El resultat és el nombre d'enviaments totals que s'han fet al problema 
      del paràmetre implícit.
  */
  int consulta_enviaments_totals() const;

  /** @brief Consulta el nombre d'enviaments exitosos. 
      \pre <em>cert</em>
      \post El resultat és el nombre d'enviaments amb èxit que s'han fet al problema del paràmetre implícit.
  */
  int consulta_enviaments_exitosos() const;

  /** @brief Consulta la ràtio del problema. 
      \pre <em>cert</em>
      \post El resultat és la ràtio (t + 1)/(e + 1) del problema del paràmetre implícit.
  */
  int consultar_ratio() const;
  
  
  // Escriptura
    
  /** @brief Operació d'escriptura d'un problema.
      \pre <em>cert</em>
      \post S'ha escrit pel canal estàndard de sortida el problema del paràmetre implícit,
      mostrant mostrant el nombre d'enviaments totals i el nombre e d'enviaments amb èxit.
      També s'ha escrit el ser ràtio (t + 1)/(e + 1).    
  */
  void escriure() const;

};
#endif
