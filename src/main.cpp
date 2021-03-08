#include <iostream>
#include "musica.h"
#include "musicas.h"
#include "playlist.h"

using namespace std;

// Função principal do programa
int main() {
    Musicas *musicas = new Musicas();
    Playlist *playlist = new Playlist();

    cout << "+----------------------------------+" << endl;
    cout << "| Seja bem Vindo!                  |"<< endl;
    cout << "| Este é um aplicativo de músicas. |"<< endl;
    cout << "| Divirta-se e aproveite!          |" << endl;
    cout << "+----------------------------------+" << endl;

    bool sair = false;
    int opcao;

    do{
        cout << "+------------- MENU ----------------------------+" << endl;
        cout << "|[00] - Sair                                    |" << endl;
        cout << "|[01] - Adicionar uma música                    |" << endl;
        cout << "|[02] - Visualizar todas as músicas             |" << endl;
        cout << "|[03] - Buscar uma música                       |" << endl;
        cout << "|[04] - Apagar uma música                       |" << endl;
        cout << "|[05] - Adicionar n músicas                     |" << endl;
        cout << "|[06] - Apagar n músicas                        |" << endl;
        cout << "|[07] - Concatenação de duas listas de músicas  |" << endl;
        cout << "|[08] - Remover última música da lista global   |" << endl;
        cout << "|[09] - Criar uma música no final da lista geral|" << endl;
        cout << "|[10] - Adicionar uma playlist                  |" << endl;
        cout << "|[11] - Adicionar uma música a playlist         |" << endl;
        cout << "|[12] - Remover uma música de uma playlist      |" << endl;
        cout << "|[13] - Lista músicas por playlists             |" << endl;
        cout << "|[14] - Adicionar várias músicas a uma playlist |" << endl;
        cout << "|[15] - Remover várias músicas de uma playlist  |" << endl;
        cout << "|[16] - Juntar duas playlists                   |" << endl;
        cout << "|[17] - Copiar uma playlist com uma música      |" << endl;
        cout << "|[18] - Criar playlist sem elementos repetidos  |" << endl;
        cout << "|[19] - Remover uma música de uma playlist      |" << endl;
        cout << "|[20] - Remover na última posição da playlist   |" << endl;
        cout << "|[21] - Inserir na última posição da playlist   |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "Digite uma opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 0: {
                cout << "Caminho no sistema: Menu > Opção 0\n" << endl;
                sair = true;

                delete musicas;
                delete playlist;

                break;
            } case 1: {
                cout << "Caminho no sistema: Menu > Opção 1\n" << endl;
                musicas->criar(musicas);
                cout << endl;
                break;  
            } case 2: {
                cout << "Caminho no sistema: Menu > Opção 2\n" << endl;
                musicas->listar();
                cout << endl;
                break;  
            } case 3: {
                cout << "Caminho no sistema: Menu > Opção 3\n" << endl;
                musicas->buscar();
                break; 
            } case 4: {
                cout << "Caminho no sistema: Menu > Opção 4\n" << endl;
                musicas->apagar(musicas);
                break;  
            } case 5: {
                cout << "Caminho no sistema: Menu > Opção 5\n" << endl;
                musicas->adicionar(musicas);
                break;
            } case 6: {
                cout << "Caminho no sistema: Menu > Opção 6\n" << endl;
                musicas->remover(musicas);
                break;  
            } case 7: {
                cout << "Caminho no sistema: Menu > Opção 7\n" << endl;
                Musicas* novasMusicas = new Musicas();
                musicas = (musicas + *novasMusicas);
                delete novasMusicas;
                break;   
            } case 8: {
                cout << "Caminho no sistema: Menu > Opção 8\n" << endl;
                *musicas >> musicas;
                break;
            } case 9: {
                cout << "Caminho no sistema: Menu > Opção 9\n" << endl;
                *musicas << musicas;
                break; 
            } case 10: {
                cout << "Caminho no sistema: Menu > Opção 10\n" << endl;
                playlist->criar(playlist);
                break;
            } case 11: {
                cout << "Caminho no sistema: Menu > Opção 11\n" << endl;
                playlist->adicionarMusica(playlist, musicas);
                break;
            } case 12: {
                cout << "Caminho no sistema: Menu > Opção 12\n" << endl;
                playlist->removerMusica(playlist, musicas);
                break;
            } case 13: {
                cout << "Caminho no sistema: Menu > Opção 13\n" << endl;
                playlist->listarMusicasPorPlaylist(playlist);
                break;
            } case 14: {
                cout << "Caminho no sistema: Menu > Opção 14\n" << endl;
                playlist->adicionarMusica(playlist);
                break;
            } case 15: {
                cout << "Caminho no sistema: Menu > Opção 15\n" << endl;
                playlist->removerMusica(playlist);
                break; 
            } case 16: {
                cout << "Caminho no sistema: Menu > Opção 16\n" << endl;
                Playlist* novaPlaylist = new Playlist();
                playlist = (playlist + *novaPlaylist);
                break;   
            } case 17: {
                cout << "Caminho no sistema: Menu > Opção 17\n" << endl;
                Musica* musica = new Musica();
                playlist = (playlist + *musica);
                break;   
            } case 18: {
                cout << "Caminho no sistema: Menu > Opção 18\n" << endl;
                playlist = (playlist - *playlist);
                break;   
            } case 19: {
                cout << "Caminho no sistema: Menu > Opção 19\n" << endl;
                Musica* musica = new Musica();
                playlist = (playlist - *musica);
                break;         
            } case 20: {
                cout << "Caminho no sistema: Menu > Opção 20\n" << endl;
                *playlist >> playlist;
                break;         
            } case 21: {
                cout << "Caminho no sistema: Menu > Opção 21\n" << endl;
                *playlist << playlist;
                break;         
            } default: {
                cout << "Ops! Informe uma opção válida!" << endl;
                break;
            }
                   
        }
    } while(sair != true);

    return 0;
}    