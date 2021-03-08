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

// Função sobrecarregada da função de adicioanar músicas
Musicas* Musicas::adicionar(Musicas *musicas) {
    bool sair = false;
    int opcao;

    cout << "+----------------------------------+" << endl;
    cout << "| Adicione quantas músicas quiser! |"<< endl;
    cout << "+----------------------------------+" << endl;

    do{
        cout << "+----------------------------------+" << endl;
        cout << "| [0] - Sair                       |"<< endl;
        cout << "| [1] - Adicionar uma música       |"<< endl;
        cout << "+----------------------------------+" << endl;
        cout << "Digite uma opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao){
            case 0:
                sair = true;
                break;
            case 1: {
                musicas->criar(musicas);
                break;
            } default: {
                cout << "Ops! Informe uma opção válida!" << endl; 
                break;
            }    
        }
    }while(!sair);

    return musicas;
}

Musicas* Musicas::unirDuasListasMusica(Musicas *primeira, Musicas *segunda) {
    Musicas* novaLista = new Musicas();
    linkedList *primeiraListaLigada = new linkedList;
    linkedList *segundaListaLigada = new linkedList;

    primeiraListaLigada = primeira->cabeca;  
    segundaListaLigada = segunda->cabeca;

    while(primeiraListaLigada != NULL) {
      novaLista->adicionar(primeiraListaLigada->musica);  
      primeiraListaLigada = primeiraListaLigada->proximo;
    }

    while(segundaListaLigada != NULL) {
      Musica *musica = new Musica();
      musica = novaLista->procurarMusica(segundaListaLigada->musica.getTitulo());  

      if(musica->getTitulo().empty()) {
          novaLista->adicionar(segundaListaLigada->musica);
      }

      segundaListaLigada = segundaListaLigada->proximo;
    }

    return novaLista;
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

            cout << "Música " + tituloMusica + " apagada!" << endl;

            break; 
        } else {
            anterior = atual; 
            atual = atual->proximo;
        }
    }
}

// Função sobrecarregar da função de remover músicas
Musicas* Musicas::remover(Musicas *musicas) {
    bool sair = false;
    int opcao;

    cout << "+----------------------------------+" << endl;
    cout << "| Apague quantas músicas quiser!   |"<< endl;
    cout << "+----------------------------------+" << endl;

    do{
        cout << "+----------------------------------+" << endl;
        cout << "| [0] - Sair                       |"<< endl;
        cout << "| [1] - Remover uma música       |"<< endl;
        cout << "+----------------------------------+" << endl;
        cout << "Digite uma opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao){
            case 0:
                sair = true;
                break;
            case 1: {
                musicas->apagar(musicas);
                break;
            }default:  {
                cout << "Ops! Informe uma opção válida!" << endl; 
                break;
            }
        }
    }while(!sair);

    return musicas;
}

// Função responsável por apagar uma música
void Musicas::listar() {
    linkedList *atual = new linkedList;
    atual = cabeca;   

    int contador = 1;

    if(atual == NULL) {
        cout << "Nenhuma música encontrada!" << endl; 
    }

    while(atual != NULL) {
        if(!atual->musica.getTitulo().empty()) {
            cout << contador << ": " << atual-> musica.getTitulo() << endl;
        }
  
        atual = atual->proximo;
        contador += 1;
    }
}

// Função responsável por procurar uma música
Musica* Musicas::procurarMusica(string nomeMusica) {
    linkedList *atual = new linkedList;
    atual = cabeca;

    int count = 1;

    Musica *musica = new Musica();

    while(atual != NULL) {
      if(atual->musica.getTitulo().compare(nomeMusica) == 0) {
          musica = &atual->musica;
          return musica;
      }   

      atual = atual->proximo;
    }

    return musica;
}

// Função responsável por criar uma nova música
Musicas* Musicas::criar(Musicas *musicas) {
    string titulo, autor;

    cout << "Digite o título: ";
    cin >> ws; 
    getline(cin,titulo);

    cout << "Digite o nome do autor: ";
    cin >> ws; 
    getline(cin,autor); 

    Musica *musica = new Musica(titulo, autor);

    musicas->adicionar(*musica);

    return musicas;
}

// Função responsável por apagar uma nova música
Musicas* Musicas::apagar(Musicas *musicas) {
    string titulo;

    cout << "Digite o título: ";
    cin >> ws;
    getline(cin,titulo); 

    musicas-> deletar(titulo);

    cout << endl;

    return musicas;
}

// Função responsável por buscar uma nova música
void Musicas::buscar() {
    string titulo;

    cout << "Digite o título: ";
    cin >> ws; 
    getline(cin,titulo);

    Musica* musica = procurarMusica(titulo);

    if(!musica->getTitulo().empty()) {
        cout << "Música encontrada! Que tal colocar " + musica->getTitulo() + " para tocar?\n" << endl;
    }else{
        cout << "Infelizmente não foi possível encontrar a música " + titulo + "!" << endl;
        cout << "Que tal adicioná-la pela opção 1 no menu?\n" << endl;
    }
}

// Função responsável por concatenar duas listas de músicas
Musicas* Musicas::concatenar(Musicas* primeiraLista, Musicas segundaLista) {
    Musicas* musicas = new Musicas();

    linkedList *primeiraListaLikada = new linkedList;
    primeiraListaLikada = primeiraLista->cabeca;   

    while(primeiraListaLikada != NULL) {
        musicas->adicionar(primeiraListaLikada->musica);
        primeiraListaLikada = primeiraListaLikada->proximo;
    }

    return musicas;
}

// Função responsável por apagar a última música da lista de música
Musicas* Musicas::apagarUltimaMusica(Musicas* musicas) {
    linkedList *atual = new linkedList;
    linkedList *anterior = new linkedList;

    atual = musicas->cabeca;

    while(atual != NULL) {
        if(atual->proximo == NULL) {
            cout << "Música " + atual->musica.getTitulo() + " apagada!" << endl;
            anterior->proximo = atual->proximo;
            delete atual;
            break;
        }

        anterior = atual; 
        atual = atual->proximo;
    }

    if(atual == NULL) {
        cout << "Não é possível apagar a última música, porque a lista está vazia!" << endl;
    }

    return musicas;
}

// Função responsável por criar uma música na última posição
Musicas* Musicas::criarMusicaUltimaPosicao(Musicas* lista) {
    linkedList *atual = new linkedList;
    string titulo, autor;

    cout << "Digite o título: ";
    cin >> ws; 
    getline(cin,titulo);

    cout << "Digite o nome do autor: ";
    cin >> ws; 
    getline(cin,autor); 

    Musica *musica = new Musica(titulo, autor);

    atual = lista->cabeca;

    if(atual != NULL) {
        while(atual != NULL) {
            if(atual->proximo == NULL) {
                break;
            }

            atual = atual->proximo;
        }

        linkedList *temporaria = new linkedList;
        temporaria->musica = *musica;
        temporaria->proximo = NULL;

        atual->proximo = temporaria;
    }else{
        lista->adicionar(*musica);
    }

    return lista;
}