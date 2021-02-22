#include <iostream>
#include "playlist.h"

// Função responsável por adicionar uma playlist
void Playlist::adicionar(string nome, Musicas *musicas) {
    linkedPlaylist *temporaria = new linkedPlaylist;
    temporaria->nome=nome;
    temporaria->musicas=musicas;
    temporaria->proxima = cabeca;
    cabeca = temporaria;
}

// Função responsável por procurar uma playlist
linkedPlaylist Playlist::procurarPlaylist(string nomePlaylist) {
    linkedPlaylist *atual = new linkedPlaylist;
    atual = cabeca;

    linkedPlaylist *lista = new linkedPlaylist();

    while(atual != NULL) {
      if(atual->nome.compare(nomePlaylist) == 0) {
          lista = atual;
          return *lista;
      }   

      atual = atual->proxima;
    }

    cout << "Não foi possível encontrar!" << endl;
    return *lista;
}