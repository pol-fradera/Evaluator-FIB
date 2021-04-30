/** @file Sessio.hh
    @brief Especificació de la classe Sessio
*/

#ifndef _SESSIO_HH_
#define _SESSIO_HH_


#ifndef NO_DIAGRAM 
#include "BinTree.hh"
#include <iostream>
#include <set>
#endif

/** @class Sessio
    @brief Representa les característiques d'una sessio. 
*/

class Sessio {

private:
    
  BinTree<string> ap;
  
  set<string> sp;
  
  static int size(const BinTree<string>& a);
  
  BinTree<string> llegir_bintree();
  
  static void escriure_BinTree(const BinTree<string>& a);
  
public:
    
  //Constructores

   /** @brief Creadora per defecte. 

      S'executa automàticament al declarar una sessió.
      \pre <em>cert</em>
      \post El resultat és una sessió buida.
  */
  Sessio();
  
   /** @brief Creadora amb paràmetre. 
      \pre <em>cert</em>
      \post El resultat és una sessió amb identificador s.
  */
  Sessio(string s);

    
  //Modificadores

  /** @brief Afageix problemes a la sessió.
      \pre Està preparat al canal estàndard una seqüència d'identificadors de 
      problemes, seguint un recorregut en preordre de la seva estructura de prerequisits.
      \post S'ha afegit al paràmetre implícit un BinTree de problemes amb els seus 
      identificadors p.
  */
  void afegir_problemes();
    
  // Consultores
  
  int mida() const;
  
  bool conte_problema(string p) const;
  
  string problemes_env() const;
  
  
  // Escriptura
    
  /** @brief Operació d'escriptura d'una sessió.
      \pre <em>cert</em>
      \post S'ha escrit pel canal estàndard de sortida la sessió del paràmetre implícit,
      mostrant el nombre de problemes que la formen i els identificadors d'aquests 
      problemes, seguint la seva estructura de prerequisits en postordre.
  */
  void escriure() const;
  
  
  void llegir();
  
    
  
};
#endif
