/** @file Cjt_usuaris.hh
    @brief Especificació de la classe Cjt_usuaris
*/

#ifndef _CJT_USUARIS_HH_
#define _CJT_USARIS_HH_

#include "Usuari.hh"
#include "Cjt_cursos.hh"
#include "Cjt_problemes.hh"

#ifndef NO_DIAGRAM 
#include <map>
#endif

/** @class Cjt_usuaris
    @brief Representa el conjunt d'usuaris de l'evaluator. 
*/

class Cjt_usuaris {

private:
    
  map<string, Usuari> mu;
  
public:

  //Constructora

  /** @brief Creadora per defecte. 

      S'executa automàticament al declarar un conjunt d'usuaris.
      \pre <em>cert</em>
      \post El resultat és un conjunt d'usuaris buit.
  */
  Cjt_usuaris();

  
  //Modificadores
  
  /** @brief Afageix un usuari al conjunt d'usuaris.
      \pre El paràmetre implícit no conté cap usuari amb l'identificador u.
      \post S'ha afegit una nou usuari amb identificador u al paràmetre implícit i
      s'ha escrit pel canal estàndard de sortida el nombre d'usuaris del conjunt 
      després de ser afegit al paràmetre implícit.
  */  
  void alta_usuari(string u);
  
  /** @brief Elimina un usuari del conjunt d'usuaris.
      \pre El paràmetre implícit conté un usuari amb l'identificador u.
      \post S'ha esborrat l'usuari amb identificador u del paràmetre implícit i
      s'ha escrit pel canal estàndard de sortida el nombre d'usuaris del conjunt 
      després de ser eliminat del paràmetre implícit.
  */
  void baixa_usuari(string u);
  
  /** @brief S'apunta el resultat d'un nou enviament d'un usuari a un problema.
      \pre L'usuari amb identificador u està registrat i inscrit en un curs on 
      apareix el problema p, i p pertany al conjunt de problemes als que u pot
      enviar.
      \post S'han actualitzat les estadístiques de l'usuari i del problema.
  */
  void enviament(string u, string p, int& r);
  
  /** @brief Inscriu un usuari en un curs.
      \pre El paràmetre implícit conté un usuari amb l'identificador u, el curs c 
      existeix i l'usuari no està inscrit en cap altre curs sense completar.
      \post S'ha inscrit l'usuari amb identificador u del paràmetre implícit al 
      curs c i s'ha escrit pel canal estàndard de sortida el nombre d'usuaris 
      inscrits en el curs c després de ser afegit.
  */
  void inscriure_curs(string u, int c);
  
  /** @brief Esborra un usuari d'un curs.
      \pre El paràmetre implícit conté un usuari amb l'identificador u, el curs c 
      existeix i l'usuari està inscrit en el curs c.
      \post S'ha esborrat l'usuari amb identificador u del curs c.
  */
  void esborrar_del_curs(string u, int c);
      
  
    //Consultores

  /** @brief Consulta si l'usuari u es troba al conjunt. 
      \pre <em>cert</em>
      \post Indica si el conjunt conté l'usuari u.
  */
  bool existeix_usuari(string u);
  
  /** @brief Consulta si l'usuari es troba inscrit en algun curs no completat. 
      \pre <em>cert</em>
      \post Indica si l'usuari u està inscrit en algun curs no completat.
  */
  bool esta_inscrit_nc(string u);
  
  /** @brief Consulta si l'usuari es troba inscrit en algun curs. 
      \pre <em>cert</em>
      \post Indica si l'usuari u està inscrit en algun curs.
  */
  bool esta_inscrit(string u);

  /** @brief Consulta si l'usuari es troba inscrit en un curs on apareix el problema. 
      \pre <em>cert</em>
      \post Indica si l'usuari u està inscrit en un curs on apareix el problema c.
  */
  bool esta_inscrit_curs_pr(string u, string p);
  
  /** @brief Consulta si l'usuari pot enviar una solució al problema.
      \pre <em>cert</em>
      \post Indica si l'usuari u pot enviar una solució al problema p per complir 
      els prerquisits.
  */
  bool compleix_requisit(string u, string p);
  
  /** @brief Consulta el curs en que està inscrit un usuari. 
      \pre El paràmetre implícit conté un usuari amb l'identificador u.
      \post S'ha escrit pel canal estàndard de sortida l'identificador del 
      curs en que l'usuari u està inscrit o un zero si no està inscrit en 
      cap curs.
  */
  void curs_usuari(string u);

  /** @brief Es llisten en ordre creixent per identificador els problemes 
      solucionats amb exit per l'usuari. 
      \pre El paràmetre implícit conté un usuari amb l'identificador u.
      \post S'ha escrit pel canal estàndard de sortida una llista en ordre
      creixent per identificadors els problemes solucionats amb exit per 
      l'usuari u. Tambe s'ha escrit el nombre d'enviaments realitzats per 
      l'usuari a cada problema del llistat.
  */
  void problemes_resolts(string u);
  
  /** @brief Es llisten en ordre creixent per identificador els problemes que 
      l'usuari no ha solucionat. 
      \pre El paràmetre implícit conté un usuari amb l'identificador u.
      \post S'ha escrit pel canal estàndard de sortida una llista en ordre
      creixent per identificadors els problemes que l'usuari u no ha solucionat 
      del curs en que està inscrit i pot realitzar el seu enviament. Tambe s'ha
      escrit el nombre d'enviaments realitzats per l'usuari a cada problema del
      llistat.
  */
  void problemes_enviables(string u);
  
  /** @brief Consulta el nombre d'usuaris del conjunt. 
      \pre <em>cert</em>
      \post El resultat és el nombre d'ususaris del paràmetre implícit.
  */
  int mida() const;
    
    
  // Lectura i escriptura
  
  /** @brief Operació de lectura del conjunt d'usuaris.
      \pre Estan preparats al canal estàndard d'entrada un enter, que representa 
      el nombre d'usuaris que llegirem, i una seqüència d'strings que 
      identifiquen aquests ususaris. 
      \post El paràmetre implícit conté el conjunt d'usuaris llegits del canal 
      estàndard d'entrada.
  */
  void llegir_usuaris();

  /** @brief Operació d'escriptura del conjunt d'usuaris.
      \pre <em>cert</em> 
      \post S'han escrit pel canal estàndard de sortida els usuaris del conjunt,
      ordenats creixentmenr pel seu nom i mostrant, per cada usuari, el nombre  
      d'enviaments totals que ha realitzat, quants problemes ha resolt 
      satisfactòriament, quants problemes ha intentat resoldre, i l'identificador 
      del curs en que està inscrit o un zero i no està inscrit en cap curs.
  */
  void llistar_usuaris() const;
  
  /** @brief Operació d'escriptura d'un ususari.
      \pre El paràmetre implícit conté una usuari amb l'identificador u.
      \post S'ha escrit pel canal estàndard de sortida l'usuari u del conjunt,
      mostrant el nombre d'enviaments totals que ha realitzat, quants problemes 
      ha resolt satisfactòriament, quants problemes ha intentat resoldre, i 
      l'identificador del curs en que està inscrit o un zero i no està inscrit en 
      cap curs.
  */
  void escriure_usuari(string u);
};
#endif
