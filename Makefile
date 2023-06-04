all: testa_rainhas.cpp   rainhas.cpp rainhas.hpp rainhas.o
	cpplint --linelength=120 --exclude=catch.hpp --filter=-build/include rainhas.cpp
	cpplint --linelength=120 --exclude=catch.hpp testa_rainhas.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -g rainhas.o testa_rainhas.cpp -o testa_rainhas
	cppcheck --enable=warning --config-excludes-file=catch.hpp .
	./testa_rainhas
	gcov *.cpp
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_rainhas

windows: testa_rainhas.cpp   rainhas.cpp rainhas.hpp rainhas.o
	cpplint --linelength=120 --exclude=catch.hpp --filter=-build/include rainhas.cpp
	cpplint --linelength=120 --exclude=catch.hpp testa_rainhas.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -g rainhas.o testa_rainhas.cpp -o testa_rainhas
	cppcheck --enable=warning --config-excludes-file=catch.hpp .
	./testa_rainhas
	gcov *.cpp

compile: testa_rainhas.cpp   rainhas.cpp rainhas.hpp rainhas.o
	g++ -std=c++11 -Wall rainhas.o testa_rainhas.cpp -o testa_rainhas
	
test: testa_rainhas	
	./testa_rainhas
	
cpplint: testa_rainhas.cpp   rainhas.cpp rainhas.hpp
	cpplint   --exclude=catch.hpp  *.*
	
gcov: testa_rainhas.cpp   rainhas.cpp rainhas.hpp 
	g++ -std=c++11 -Wall -Wall -fprofile-arcs -ftest-coverage -c rainhas.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage rainhas.o testa_rainhas.cpp -o testa_rainhas
	./testa_rainhas
	gcov *.cpp	
	
debug: testa_rainhas.cpp   rainhas.cpp rainhas.hpp 
	g++ -std=c++11 -Wall -Wall -g -c rainhas.cpp
	g++ -std=c++11 -Wall  -g rainhas.o testa_rainhas.cpp -o testa_rainhas
	gdb testa_rainhas
	
	
cppcheck: testa_rainhas.cpp   rainhas.cpp rainhas.hpp
	cppcheck  --enable=warning . 

valgrind: testa_rainhas
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_rainhas

rainhas.o : rainhas.cpp rainhas.hpp
	g++ -std=c++11 -Wall -Wall -c rainhas.cpp
	
testa_rainhas: 	testa_rainhas.cpp   rainhas.cpp rainhas.hpp rainhas.o
	g++ -std=c++11 -Wall rainhas.o testa_rainhas.cpp -o testa_rainhas

clean:
	rm -rf *.o *.exe *.gc* ataquesArquivoTesteColuna.txt ataquesArquivoTesteDiagonalPrincipal.txt ataquesArquivoTesteDiagonalSecundaria.txt ataquesArquivoTesteLinha.txt ataques.txt
	
	
