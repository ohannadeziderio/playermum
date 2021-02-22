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
        cout << "+------------- MENU ------------------------+" << endl;
        cout << "|[0] - Sair                                 |" << endl;
        cout << "|[1] - Adicionar uma música                 |" << endl;
        cout << "|[2] - Visualizar todas as músicas          |" << endl;
        cout << "|[3] - Apagar uma música                    |" << endl;
        cout << "|[4] - Adicionar uma playlist               |" << endl;
        cout << "|[5] - Adicionar uma música a playlist      |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "Digite uma opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 0: {
                sair = true;
                break;
            } case 1: {
                cout << "+------------- ADICIONAR UMA MÚSICA ---------------+" << endl;

                string titulo, autor;

                cout << "Digite o título: ";
                cin >> ws; 
                getline(cin,titulo);

                cout << "Digite o nome do autor: ";
                cin >> ws; 
                getline(cin,autor); 

                Musica *musica = new Musica(titulo, autor);

                musicas->adicionar(*musica);

                cout << endl;
                break;  
            } case 2: {
                cout << "+------------- LISTAR TODAS AS MÚSICAS ---------------+" << endl;

                musicas->listar();

                cout << endl;
                break;  
            } case 3: {
                cout << "+------------- REMOVER UMA MÚSICA ---------------+" << endl;

                string titulo;

                cout << "Digite o título: ";
                cin >> ws;
                getline(cin,titulo); 

                musicas-> deletar(titulo);

                cout << endl;
                break;  
            } case 4: {
                cout << "+------------- ADICIONAR UMA PLAYLIST ---------------+" << endl;
                
                Musicas *musicas = new Musicas();
                string nome;

                cout << "Digite o nome da playlist: ";
                cin >> ws;
                getline(cin,nome); 

                playlist->adicionar(nome, musicas);

                cout << endl;
                break;
            } case 5: {
                cout << "+------------- ADICIONAR UMA MÚSICA A PLAYLIST ---------------+" << endl;

                string nome, titulo;

                cout << "Digite o nome da playlist: ";
                cin >> ws;
                getline(cin,nome); 

                linkedPlaylist lista = playlist->procurarPlaylist(nome);

                if(!lista.nome.empty()) {
                    cout << "Digite o título da música: ";
                    cin >> ws;
                    getline(cin,titulo);

                    Musica *musica = new Musica(); 
                    *musica = musicas->procurarMusica(titulo);

                    if(!musica->getTitulo().empty()) {
                        lista.musicas->adicionar(*musica);
                    }
                }

                cout << "Música adicionada! " << endl;
                cout << endl;
                break;
            }
            default:
                cout << "Ops! Informe uma opção válida!" << endl;   
        }
    } while(sair != true);

    return 0;
}    