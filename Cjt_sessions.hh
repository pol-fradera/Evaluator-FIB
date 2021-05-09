/** @file Cjt_sessions.hh
    @brief Especificació de la classe Cjt_sessions
*/

#ifndef _CJT_SESSIONS_HH_
#define _CJT_SESSIONS_HH_

#include "Sessio.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <map>
#include <iostream>
#endif

/** @class Cjt_sessions
    @brief Representa el conjunt de sessions de l'evaluator. 
*/

class Cjt_sessions {

private:

  map<string, Sessio> ms;
  
public:

  //Constructora

  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un conjunt de sessions.
      \pre <em>cert</em>
      \post El resultat és un conjunt de sessions buit.
  */  
  Cjt_sessions();
   
  //Modificadores
  
  /** @brief Afageix una sessió al conjunt de sessions.
      \pre El paràmetre implícit no conté cap sessió amb l'identificador s.
      \post S'ha afegit una nova sessió amb identificador s al paràmetre implícit i
      s'ha escrit pel canal estàndard de sortida el nombre de sessions del conjunt 
      després d'afegir-la al paràmetre implícit.
  */
  void nova_sessio(string s);

  bool actualitzar_env(string s, string p, string& p1, string& p2);
      
  //Consultores
  
  /** @brief Consulta el nombre de sessions del conjunt. 
      \pre <em>cert</em>
      \post El resultat és el nombre de sessions del paràmetre implícit.
  */
  int mida() const;
  
  /** @brief Consulta si la sessio s es troba al conjunt. 
      \pre <em>cert</em>
      \post Indica si el conjunt conté la sessio s.
  */
  bool existeix_sessio(string s) const;
  
  bool sessio_problema(string s, string p) const;
  
  string problemes_env(string s) const;

  bool interseccio(string s1, string s2) const;
    
    
  // Lectura i escriptura

  /** @brief Operació de lectura del conjunt de sessions.
      \pre Estan preparats al canal estàndard d'entrada un enter (més gran que 0), 
      que representa el nombre de session que llegirem, i una seqüència 
      d'strings que identifiquen aquestes sessions. Per a cada sessió s'entrarà
      el seu nom i una seqüència d'identificadors de problemes, seguint un 
      recorregut en preordre. 
      \post El paràmetre implícit conté el conjunt de sessions llegits del canal estàndard d'entrada amb els identificadors dels problemes pertinents a cada sessió.
  */
  void llegir_sessions();

  /** @brief Operació d'escriptura del conjunt de sessions.
      \pre <em>cert</em> 
      \post S'han escrit pel canal estàndard de sortida les sessions del conjunt,
      ordenades pel seu identificador i mostrant, per cada sessió, el nombre de 
      problemes que la formen i els identificadors d'aquests problemes, seguint
      la seva estructura de prerequisits en postordre.
  */
  void llistar_sessions() const;
  
  /** @brief Operació d'escriptura d'una sessio.
      \pre El paràmetre implícit conté una sessio amb l'identificador s.
      \post S'ha escrit pel canal estàndard de sortida la sessio s del conjunt,
      mostrant el nombre de problemes que la formen i els identificadors d'aquests 
      problemes, seguint la seva estructura de prerequisits en postordre.
  */
  void escriure_sessio(string s) const;
};
#endif
