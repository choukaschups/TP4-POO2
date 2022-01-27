GPP_FLAGS = -ansi -pedantic -Wall -std=c++17

all: main

main: main.o ActionAfficherClassement.o ActionCreerGraphe.o CritereHeure.o CritereType.o Lecteur.o Requete.o
	g++ $(GPP_FLAGS) -g -o main main.o ActionAfficherClassement.o ActionCreerGraphe.o CritereHeure.o CritereType.o Lecteur.o Requete.o

%.o: %.cpp
	g++ $(GPP_FLAGS) -c $<

clean:
	rm *.o