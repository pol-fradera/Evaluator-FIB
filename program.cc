/** @mainpage
    En el mòdul program.cc es troba el programa principal.
    Per l'aplicació per a la plataforma EVALUATOR, necesitarem un mòdul
    per representar l'Usuari, un altre pel Problema, un altre per la Sessio i
    un altre pel Curs, a mes de 4 mòduls per a cada conjunt d'aquests, 
    Cjt_usuaris, Cjt_problemes, Cjt_sessions i Cjt_cursos.
*/

/** @file program.cc
    @brief Programa principal
    
    <em>Aplicació per a la plataforma EVALUATOR</em>.
*/

#include "Cjt_cursos.hh"
#include "Cjt_sessions.hh"
#include "Cjt_problemes.hh"
#include "Cjt_usuaris.hh"

#ifndef NO_DIAGRAM 
#endif

int main() {
    Cjt_problemes pr;
    pr.llegir_problemes();
    
    Cjt_sessions se;
    se.llegir_sessions();
    
    Cjt_cursos cu;
    cu.llegir_cursos();

    Cjt_usuaris us;
    us.llegir_usuaris();  
    
    string comanda;
    cin >> comanda;
    while (comanda != "fin") {
        string p, s, u;     // Identificador del problema, de la sessó i de l'usuari
      //int c, r;   // Identificador del curs i nota del resultat de l'enviament
        if (comanda == "np" or comanda == "nuevo_problema") {
            cin >> p;
            cout << '#' << comanda << ' ' << p << endl;
            if (not pr.existeix_problema(p)) pr.nou_problema(p);
            else cout << "error: el problema ya existe" << endl;
        }
        /*else if (comanda == "ns" or comanda == "nueva_sesion") {
            cin >> s;
            if (not se.existeix_sessio(s)) se.nova_sessio(s);            
        }
        else if (comanda == "nc" or comanda == "nuevo_curso") {
            cu.nou_curs();
        }
        else if (comanda == "a" or comanda == "alta_usuario") {
            cin >> u;
            if (not us.existeix_usuari(u)) us.alta_usuari(u);
            else cout << " error" << endl;
        }
        else if (comanda == "b" or comanda == "baja_usuario") {
            cin >> u;
            if (us.existeix_usuari(u)) us.baixa_usuari(u);
            else cout << " error" << endl;
        }
        else if (comanda == "i" or comanda == "inscribir_curso") {
            cin >> u >> c;
            if (us.existeix_usuari(u) and cu.existeix_curs(c) and not us.esta_inscrit_nc(u)) us.inscriure_curs(u, c);
            else cout << " error" << endl;
        }
        else if (comanda == "cu" or comanda == "curso_usuario") {
            cin >> u;
            if (us.existeix_usuari(u)) us.curs_usuari(u);
            else cout << " error" << endl;
        }
        else if (comanda == "sp" or comanda == "sesion_problema") {
            cin >> c >> p;
            if (cu.existeix_curs(c) and pr.existeix_problema(p) and pr.pertany_curs(c, p)) pr.sessio_problema(c, p);
            else cout << " error" << endl;
        }            
        else if (comanda == "pr" or comanda == "problemas_resueltos") {
            cin >> u;
            if (us.existeix_usuari(u)) us.problemes_resolts(u);
            else cout << " error" << endl;
        }
        else if (comanda == "pe" or comanda == "problemas_enviables") {
            cin >> u;
            if (us.existeix_usuari(u) and us.esta_inscrit(u)) us.problemes_enviables(u);
            else cout << " error" << endl;
        }
        else if (comanda == "e" or comanda == "envio") {
            cin >> u >> p >> r;
            if (us.existeix_usuari(u) and us.esta_inscrit_curs_pr(u, p) and us.compleix_requisit(u, p)) us.enviament(u, p, r);
            else cout << " error" << endl;
        } */           
        else if (comanda == "lp" or comanda == "listar_problemas") {
            cout << '#' << comanda << endl;
            pr.llistar_problemes();
        }
        else if (comanda == "ep" or comanda == "escribir_problema") {
            cin >> p; 
            cout << '#' << comanda << ' ' << p << endl;
            if (pr.existeix_problema(p)) pr.escriure_problema(p);
            else cout << "error: el problema no existe" << endl;
        }
        else if (comanda == "ls" or comanda == "listar_sesiones") {
            cout << '#' << comanda << endl;
            se.llistar_sessions();
        }
        else if (comanda == "es" or comanda == "escribir_sesion") {
            cin >> s;
            cout << '#' << comanda << ' ' << s << endl;
            if (se.existeix_sessio(s)) se.escriure_sessio(s);
            else cout << "error: la sesion no existe" << endl;
        }
        else if (comanda == "lc" or comanda == "listar_cursos") {
            cout << '#' << comanda << endl;
            cu.llistar_cursos();
        }
        /*else if (comanda == "ec" or comanda == "escribir_curso") {
            cin >> c;
            if (cu.existeix_curs(c)) cu.escriure_curs(c);
            else cout << " error" << endl;
        }
        else if (comanda == "lu" or comanda == "listar_usuarios") us.llistar_usuaris();
        else if (comanda == "eu" or comanda == "escribir_usuario") {
            cin >> u;
            if (us.existeix_usuari(u)) us.escriure_usuari(u);
            else cout << " error" << endl;
        }*/
        cin >> comanda;
    }
}
