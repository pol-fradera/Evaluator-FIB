/** @file Curs.hh
    @brief Especificació de la classe Curs
*/

#ifndef _CURS_HH_
#define _CURS_HH_

#include "Cjt_sessions.hh"

#ifndef NO_DIAGRAM 
#include <vector>
#include <iostream>
#endif

/** @class Curs
    @brief Representa les característiques d'un curs. 
*/
class Curs {

  vector<string> vs;
  
  int us_comp, us_ins; 

public:
  //Constructores
   
  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un curs.
      \pre <em>cert</em>
      \post El resultat és un curs buit.
  */
  Curs();
  
  /** @brief Creadora amb paràmetre. 
      \pre <em>cert</em>
      \post El resultat és un curs amb identificador c.
  */
  Curs(int c);

    
  //Modificadores

  /** @brief Afegeix sessions a un curs.
      \pre Està preparat al canal estàndard d'entrada el nombre de sessions Sc > 0 del curs 
      i una seqüència Sc d'identificadors de sessions, vàlids i sense repeticions.
      \post S'ha afegit al paràmetre implícit el conjunt d'identificadors de les sessions. 
  */
  void afegir_sessions();
  
  /** @brief Aumenta el nombre d'usuaris inscrits al curs. 
      \pre <em>cert</em>
      \post El curs té un usuari més inscrit.
  */
  void sumar_usuari(); 
    

  //Consultores

  /** @brief Consulta el nombre d'usuaris del curs. 
      \pre <em>cert</em>
      \post El resultat és el nombre de d'usuaris del paràmetre implícit.
  */
  int usuaris_inscrits();
  
  
  // Escriptura

  /** @brief Operació d'escriptura d'un curs.
      \pre <em>cert</em>
      \post S'ha escrit pel canal estàndard de sortida el curs del paràmetre implícit,
      mostrant el nombre d'usuaris actuals o passats que l'han completat,
      el nombre d'usuaris inscrits actualment, el nombre de sessions que el formen 
      i els seus identificadors, en el mateix ordre que es van llegir quan es va crear el curs.
  */
  void escriure() const;
  
  void llegir(int m);

};
#endif
