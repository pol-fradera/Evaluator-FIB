/** @file Cjt_cursos.hh
    @brief Especificació de la classe Cjt_cursos
*/

#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_

#include "Curs.hh"
#include "Cjt_sessions.hh"

#ifndef NO_DIAGRAM 
#include <vector>
#endif

/** @class Cjt_cursos
    @brief Representa el conjunt de cursos de l'evaluator. 
*/

class Cjt_cursos {

private:
    
  vector<Curs> vcurs;
  
//   static int cerca_dicot(const vector<Curs>& vcurs, int left, int right, int c);
  
public:

  //Constructora
    
  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un conjunt de cursos.
      \pre <em>cert</em>
      \post El resultat és un conjunt de cursos buit.
  */
  Cjt_cursos();
  
   
  //Modificadores
  
  /** @brief Afageix un curs al conjunt de cursos.
      \pre Estan preparats al canal estàndard d'entrada un enter Sn+1 (més gran que 0), 
      que representa el número de sessions i una seqüència de Sn+1 identificadors
      vàlids de sessons.
      \post Si no hi ha intersecció de problemes entre les sessions, s'ha afegit
      un nou curs amb identificador N + 1 al paràmetre implícit i s'ha escrit pel 
      canal estàndard de sortida l'dentificador del nou curs. Altrament, s'ha escrit
      pel canal estàndard de sortida un missatge d'error.
  */  
  void nou_curs(const Cjt_sessions& se);
  
  void sumar_usuari(int c);
  
  void restar_usuari(int c);

  void actualitzar_env(int c, string p, string& p1, string& p2, const Cjt_sessions& se);
      
  
    //Consultores
  
  /** @brief Consulta si el curs c es troba al conjunt. 
      \pre <em>cert</em>
      \post Indica si el conjunt conté el curs c.
  */
  bool existeix_curs(int c) const;

  /** @brief Consulta el nombre de cursos del conjunt. 
      \pre <em>cert</em>
      \post El resultat és el nombre de cursos del paràmetre implícit.
  */
  int mida() const;
  
  /** @brief Consulta si el problema p es troba al curs c. 
      \pre <em>cert</em>
      \post Indica si el curs c conté el problema p.
  */
  bool pertany_curs(int c, string p) const;
  
  void sessio_problema(int c, string p, const Cjt_sessions& se) const;
  
  void problemes_env(int c, vector<string>& vp, const Cjt_sessions& se) const;
    
    
  // Lectura i escriptura

  /** @brief Operació de lectura del conjunt de cursos.
      \pre Estan preparats al canal estàndard d'entrada un enter N (més gran que 0), 
      que representa el nombre de cursos que llegirem, i una seqüència de N cursos, 
      identificats per l'ordre en que es llegeixen. També, per cada curs,
      està preparat el nombre de sessions Sc > 0 del curs i una seqüència Sc 
      d'identificadors de sessions, vàlids i sense repeticions.
      \post El paràmetre implícit conté el conjunt de cursos llegits del canal estàndard 
      d'entrada, amb els identificadors de sessions pertintents per cada curs.
  */
  void llegir_cursos();
 
  /** @brief Operació d'escriptura del conjunt de cursos.
      \pre <em>cert</em> 
      \post S'han escrit pel canal estàndard de sortida els cursos de la
      plataforma, ordenats creixentment pel seu identificador i mostrant,
      per cada curs, el nombre d'usuaris actuals o passats que l'han completat,
      el nombre d'usuaris inscrits actualment, el nombre de sessions que el formen 
      i els seus identificadors, en el mateix ordre que es van llegir quan es va crear el curs.
  */
  void llistar_cursos() const;

  /** @brief Operació d'escriptura d'un curs.
      \pre El paràmetre implícit conté una curs amb l'identificador c.
      \post S'ha escrit pel canal estàndard de sortida el curs c del conjunt,
      mostrant el nombre d'usuaris actuals o passats que l'han completat,
      el nombre d'usuaris inscrits actualment, el nombre de sessions que el formen 
      i els seus identificadors, en el mateix ordre que es van llegir quan es va crear el curs.
  */
  void escriure_curs(int c) const;
};
#endif
