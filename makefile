all: vektoriai progr vektoriai_O1 vektoriai_O2 vektoriai_O3

programa: vektoriai progr

vektoriai:
	g++ -c Vektoriai.cpp Funkcijos.cpp

progr:
	g++ -o Vektoriai Vektoriai.o Funkcijos.o

vektoriai_O1:
	g++ -O1 Vektoriai.cpp Funkcijos.cpp -o vektoriai_O1

vektoriai_O2:
	g++ -O2 Vektoriai.cpp Funkcijos.cpp -o vektoriai_O2

vektoriai_O3:
	g++ -O3 Vektoriai.cpp Funkcijos.cpp -o vektoriai_O3
