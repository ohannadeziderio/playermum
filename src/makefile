musica.o: musica.cpp musica.h
	g++ musica.cpp -c

musicas.o: musicas.cpp musicas.h
	g++ musicas.cpp -c

playlist.o: playlist.cpp playlist.h
	g++ playlist.cpp -c

playermun: main.cpp musica.o musicas.o playlist.o
	g++ -Wall main.cpp musica.o musicas.o playlist.o -o playermun

all: playermun
