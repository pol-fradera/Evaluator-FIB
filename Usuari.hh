/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/

#ifndef _USUARI_HH_
#define _USUARI_HH_

#include "Cjt_cursos.hh"
#include "Cjt_sessions.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <map>
#endif

/** @class Usuari
    @brief Representa les característiques d'un usuari. 
*/

class Usuari {  
    
    
private:
  
  int env_tot, pr_res, pr_int, id_curs;
  
  map<string, int> mpr_env;
  map<string, int> mpr_res;

//   set<string> spr_env;
  
public:
    
  //Constructores

  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un usuari.
      \pre <em>cert</em>
      \post El resultat és un usuari buit.
  */
  Usuari();
  
  /** @brief Creadora amb paràmetre. 
      \pre <em>cert</em>
      \post El resultat és un usuari amb identificador u.
  */
  Usuari(string u);

  //Modificadores
  
  void inscriure(int c, const Cjt_cursos& cu, const Cjt_sessions& se);

  void enviament(string p, int r, const Cjt_cursos& cu, const Cjt_sessions& se);
  
  // Consultores
  
  bool esta_inscrit() const;
  
  int consulta_curs() const;
  
  void problemes_res() const;
  
  void problemes_env() const;
  
  // Escriptura
    
  /** @brief Operació d'escriptura d'un ususari.
      \pre <em>cert</em>
      \post S'ha escrit pel canal estàndard de sortida l'usuari del paràmetre implícit,
      mostrant el nombre d'enviaments totals que ha realitzat, quants problemes 
      ha resolt satisfactòriament, quants problemes ha intentat resoldre, i 
      l'identificador del curs en que està inscrit o un zero i no està inscrit en 
      cap curs.
  */
  void escriure() const;

};
#endif
