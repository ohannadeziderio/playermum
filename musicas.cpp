#include <iostream>
#include "musicas.h"

using namespace std;

// Função responsável por adicionar uma música
void Musicas::adicionar(Musica musica) {
    linkedList *temporia = new linkedList;
    temporia->musica = musica;
    temporia->proximo = cabeca;
    cabeca = temporia;
}

// Função responsável por remover uma música
void Musicas::deletar(string tituloMusica) {
    linkedList *atual = new linkedList;
    linkedList *anterior = new linkedList;

    atual=cabeca;

    if(atual == NULL) {
        cout << "Música não encontrada!" << endl; 
    }

    while(atual != NULL) {
        string titulo = atual->musica.getTitulo();
        
        if((titulo.compare(tituloMusica)) == 0) { 
            anterior->proximo = atual->proximo;
            delete atual;

            break; 
        } else {
            anterior = atual; 
            atual = atual->proximo;
        }
    }

    cout << "Música apagada!" << endl;
}

// Função responsável por apagar uma música
void Musicas::listar() {
    linkedList *atual = new linkedList;
    atual = cabeca;   

    if(atual == NULL) {
        cout << "Nenhuma música encontrada!" << endl; 
    }

    int contador = 1;

    while(atual != NULL) {
        if(!atual->musica.getTitulo().empty()) {
            cout << contador << ": " << atual-> musica.getTitulo() << endl;
        }else{
            cout << "Nenhuma música encontrada!" << endl;
        }
  
        atual = atual->proximo;
        contador += 1;
    }
}

// Função responsável por procurar uma música
Musica Musicas::procurarMusica(string nomeMusica) {
    linkedList *atual = new linkedList;
    atual = cabeca;

    int count = 1;

    Musica *musica = new Musica();

    while(atual != NULL) {
      if(atual->musica.getTitulo().compare(nomeMusica) == 0) {
          musica = &atual->musica;
          return *musica;
      }   

      atual = atual->proximo;
    }

    cout << "Can't found the music." << endl;
    return *musica;
}