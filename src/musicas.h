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
        Musicas(const Musicas &musicas) {
            Musicas *novaLista = new Musicas();
            *novaLista = (musicas);
        }

        Musicas() {
            cabeca = NULL;
            fundo = NULL;
        } 

        // Funções
        void adicionar(Musica musica);

        Musicas* adicionar(Musicas *musicas);

        void deletar(string tituloMusica);

        Musicas* remover(Musicas *musicas);

        void listar();

        Musica* procurarMusica(string nomeMusica);

        Musicas* criar(Musicas *musicas);

        Musicas* apagar(Musicas *musicas);

        void buscar();

        Musicas* concatenar(Musicas *primeiraLista, Musicas segundaLista);

        Musicas* apagarUltimaMusica(Musicas *lista);

        Musicas* criarMusicaUltimaPosicao(Musicas *lista);

        Musicas* unirDuasListasMusica(Musicas *primeira, Musicas *segunda);

        // Sobrecarga dos operadores
        friend Musicas* operator + (Musicas* primeiraLista, Musicas const &segundaLista){
            return Musicas().concatenar(primeiraLista, segundaLista);
        }

        void operator >> (Musicas *lista) {
            Musicas().apagarUltimaMusica(lista);
        }

        void operator << (Musicas *lista) {
            Musicas().criarMusicaUltimaPosicao(lista);
        }

        // Gets e sets
        Musica getMusica();

        void setMusica();
};	
  
#endif