vektoriai:
	g++ -c Vektoriai.cpp Funkcijos.cpp

programa:
	g++ -o Vektoriai Vektoriai.o Funkcijos.o

all: vektoriai programa vektoriai_O1 vektoriai_O2 vektoriai_O3

vektoriai_O1:
	g++ -O1 Vektoriai.cpp Funkcijos.cpp -o vektoriai_O1

vektoriai_O2:
	g++ -O2 Vektoriai.cpp Funkcijos.cpp -o vektoriai_O2

vektoriai_O3:
	g++ -O3 Vektoriai.cpp Funkcijos.cpp -o vektoriai_O3
