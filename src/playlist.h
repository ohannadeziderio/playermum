#ifndef PLAYLIST_H
#define PLAYLIST_H

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
        Playlist(const Playlist &playlist) {
            Playlist *novaPlaylist = new Playlist();
            *novaPlaylist = (playlist);
        }

        Playlist() {
            cabeca = NULL;
            fundo = NULL;
        }

        // Funções
        void adicionar(string nome, Musicas *musicas);

        linkedPlaylist procurarPlaylist(string nomePlaylist);

        void listarMusicas(string nome);

        Playlist* criar(Playlist* playlist);

        Playlist* adicionarMusica(Playlist *playlist, Musicas* musicas);

        Playlist* adicionarMusica(Playlist* playlist);

        Playlist* removerMusica(Playlist *playlist, Musicas* musicas);

        Playlist* removerMusica(Playlist *playlist);

        void listarMusicasPorPlaylist(Playlist* playlist);

        Playlist* juntar(Playlist* p1, Playlist p2);

        Playlist* removerUltimaMusicaPlaylist(Playlist* playlist);

        Playlist* adicionarMusicaUltimaPosicaoPlaylist(Playlist* playlist);

        Playlist* copiarPlayListMaisUmaMusica(Playlist* lista, Musica musica);

        Playlist* novaPlaylistSemMusicasRepetidas(Playlist* p1, Playlist p2);

        Playlist* novaPlaylistMenosUmaMusica(Playlist* playlist, Musica musica);

        // Sobrecarga dos operadores
        friend Playlist* operator + (Playlist* p1, Playlist const &p2){
            return Playlist().juntar(p1, p2);
        }
        
        friend Playlist* operator + (Playlist* lista, Musica const &musica){
            return Playlist().copiarPlayListMaisUmaMusica(lista, musica);
        }

        friend Playlist* operator - (Playlist* p1, Playlist const &p2){
            return Playlist().novaPlaylistSemMusicasRepetidas(p1, p2);
        }

        friend Playlist* operator - (Playlist* playlist, Musica const &musica){
            return Playlist().novaPlaylistMenosUmaMusica(playlist, musica);
        }

        Playlist* operator >> (Playlist *playlist) {
            return Playlist().removerUltimaMusicaPlaylist(playlist);
        }

        Playlist* operator << (Playlist *playlist) {
            return Playlist().adicionarMusicaUltimaPosicaoPlaylist(playlist);
        }
};	
  
#endif