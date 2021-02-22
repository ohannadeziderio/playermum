#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musica.h"
#include "musicas.h"
#include <string>

using namespace std;

struct linkedPlaylist {
    string nome;
    Musicas *musicas;
    linkedPlaylist *proxima;
};	

// Entidade responsável por gerenciar lista de músicas
class Playlist {
    private:
        linkedPlaylist *musicas;
        linkedPlaylist *cabeca;
        linkedPlaylist *fundo;
    public:
        Playlist() {
            cabeca = NULL;
            fundo = NULL;
        }

        void adicionar(string nome, Musicas *musicas);

        linkedPlaylist procurarPlaylist(string nomePlaylist);

        void listarMusicas(string nome);
};	
  
#endif