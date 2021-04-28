OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra  -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_problemes.o Cjt_sessions.o Cjt_cursos.o Cjt_usuaris.o Problema.o Sessio.o Curs.o Usuari.o
	g++ -o program.exe program.o Cjt_problemes.o Cjt_sessions.o Cjt_cursos.o Cjt_usuaris.o Problema.o Sessio.o Curs.o Usuari.o
#
program.o: program.cc Cjt_problemes.hh Cjt_sessions.hh Cjt_cursos.hh Cjt_usuaris.hh
	g++ -c program.cc $(OPCIONS)
#
Cjt_problemes.o: Cjt_problemes.cc Cjt_problemes.hh Problema.hh
	g++ -c Cjt_problemes.cc $(OPCIONS)
#
Cjt_sessions.o: Cjt_sessions.cc Cjt_sessions.hh Sessio.hh
	g++ -c Cjt_sessions.cc $(OPCIONS)
#
Cjt_cursos.o: Cjt_cursos.cc Cjt_cursos.hh Curs.hh
	g++ -c Cjt_cursos.cc $(OPCIONS)
#
Cjt_usuaris.o: Cjt_usuaris.cc Cjt_usuaris.hh Usuari.hh
	g++ -c Cjt_usuaris.cc $(OPCIONS)
#
Problema.o: Problema.cc Problema.hh
	g++ -c Problema.cc $(OPCIONS)
#
Sessio.o: Sessio.cc Sessio.hh
	g++ -c Sessio.cc $(OPCIONS)
#
Curs.o: Curs.cc Curs.hh
	g++ -c Curs.cc $(OPCIONS)
#
Usuari.o: Usuari.cc Usuari.hh
	g++ -c Usuari.cc $(OPCIONS)
#
clean:
	rm -f *.o
	rm -f *.exe
#
program.tar: Makefile Doxyfile program.cc Cjt_problemes.hh Cjt_sessions.hh Cjt_cursos.hh Cjt_usuaris.hh Cjt_problemes.cc Cjt_sessions.cc Cjt_cursos.cc Cjt_usuaris.cc Problema.hh Sessio.hh Curs.hh Usuari.hh Problema.cc Sessio.cc Curs.cc Usuari.cc
	tar -cvf program.tar Makefile Doxyfile program.cc Cjt_problemes.hh Cjt_sessions.hh Cjt_cursos.hh Cjt_usuaris.hh Cjt_problemes.cc Cjt_sessions.cc Cjt_cursos.cc Cjt_usuaris.cc Problema.hh Sessio.hh Curs.hh Usuari.hh Problema.cc Sessio.cc Curs.cc Usuari.cc
