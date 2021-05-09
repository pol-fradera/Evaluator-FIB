/** @file Cjt_problemes.hh
    @brief Especificació de la classe Cjt_problemes
*/

#ifndef _CJT_PROBLEMES_HH_
#define _CJT_PROBLEMES_HH_

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <algorithm>
#include <vector>
#endif

/** @class Cjt_problemes
    @brief Representa el conjunt de problemes de l'evaluator. 
*/

class Cjt_problemes {

private:
  
  map<string, Problema> mp;

  static bool ordre (const pair<string, Problema>& a, const pair<string, Problema>& b); 

public:

  //Constructora
    
  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un conjunt de problemes.
      \pre <em>cert</em>
      \post El resultat és un conjunt de problemes buit.
  */
  Cjt_problemes();
  
   
  //Modificadores
  
  /** @brief Afageix un problema al conjunt de problemes.
      \pre El paràmetre implícit no conté cap problema amb l'identificador p.
      \post S'ha afegit una nou problema amb identificador p al paràmetre implícit i
      s'ha escrit pel canal estàndard de sortida el nombre de problemes del conjunt 
      després de ser afegit al paràmetre implícit.
  */  
  void nou_problema(string p);

  void actualitzar_pr(string p, int r);
  
  
  //Consultores

  /** @brief Consulta el nombre de problemes del conjunt. 
      \pre <em>cert</em>
      \post El resultat és el nombre de problemes del paràmetre implícit.
  */
  int mida() const;
  
  /** @brief Consulta si el problema p es troba al conjunt. 
      \pre <em>cert</em>
      \post Indica si el conjunt conté el problema p.
  */
  bool existeix_problema(string p) const;
  
  /** @brief Consulta la sessio del problema p en el curs amb identificador c. 
      \pre Existeix el curs c i el problema p existeix i pertany al curs c.
      \post S'ha escrit pel canal estàndard de sortida l'identificador de la 
      sessió on es realitza el problema p en el curs c.
  */
  void sessio_problema(int c, string p) const;
  
  /** @brief Consulta si el problema p es troba al curs c. 
      \pre <em>cert</em>
      \post Indica si el curs c conté el problema p.
  */
  bool pertany_curs(int c, string p) const;

    
  // Lectura i escriptura
  
  /** @brief Operació de lectura del conjunt de problemes.
      \pre Estan preparats al canal estàndard d'entrada un enter (mes gran que 0), 
      que representa el nombre de problemes que llegirem, i una seqüència 
      d'strings que identifiquen aquests problemes. 
      \post El paràmetre implícit conté el conjunt de problemes llegits del canal estàndard d'entrada.
  */
  void llegir_problemes();

  /** @brief Operació d'escriptura del conjunt de problemes.
      \pre <em>cert</em> 
      \post S'han escrit pel canal estàndard de sortida els problemes de la
      col·leccio, indicant per cada problema el nombre t d'enviaments totals
      i el nombre e d'enviaments amb exit. Tambe s'ha escrit el ratio de cada problema,
      es llisten en ordre creixen per ràtio (t + 1)/(e + 1), i en cas d'empat, per ordre creixent
      d'identificador.
  */
  void llistar_problemes() const;
  
  /** @brief Operació d'escriptura d'un problema.
      \pre El paràmetre implícit conté una problema amb l'identificador p.
      \post S'ha escrit pel canal estàndard de sortida el problema p del conjunt,
      mostrant el nombre  d'enviaments totals i el nombre e d'enviaments amb èxit.
      També s'ha escrit, per cada problema, el seu ràtio (t + 1)/(e + 1).      
  */  
  void escriure_problema(string p) const;
};
#endif
