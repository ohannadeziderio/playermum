#ifndef MUSICAS_H
#define MUSICAS_H

#include "musica.h"

using namespace std;

struct linkedList {
    Musica musica;
    linkedList *proximo;
};	

// Entidade responsável por representar uma lista ligada de música
class Musicas {
    private:
        linkedList *cabeca;
        linkedList *fundo;
    public:
        Musicas() {
            cabeca = NULL;
            fundo = NULL;
        } 

        void adicionar(Musica musica);

        void deletar(string tituloMusica);

        void listar();

        Musica procurarMusica(string nomeMusica);

        // Gets e sets
        Musica getMusica();

        void setMusica();
};	
  
#endif