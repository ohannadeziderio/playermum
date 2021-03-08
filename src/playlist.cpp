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

// Função responsável por procurar uma playlist
void Playlist::listarMusicasPorPlaylist(Playlist* playlist) {
    string nome, titulo;

    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome);

    linkedPlaylist lista = playlist->procurarPlaylist(nome);

    if(!lista.nome.empty()) {
        lista.musicas->listar();
    }else{
        cout << "Ops! Playlist não encontrada!" << endl;
    }    
}

Playlist* Playlist::criar(Playlist* playlist) {
    Musicas *musicas = new Musicas();
    string nome;

    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome); 

    playlist->adicionar(nome, musicas);

    cout << "Playlist " + nome + " criada com sucesso!" << endl;

    return playlist;
}

Playlist* Playlist::adicionarMusica(Playlist* playlist, Musicas* musicas) {
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
        musica = musicas->procurarMusica(titulo);

        if(!musica->getTitulo().empty()) {
            lista.musicas->adicionar(*musica);
            cout << "Música adicionada! " << endl;
        }
    }else{
        cout << "Ops! Playlist não encontrada!" << endl;
    }

    cout << endl;

    return playlist;
}

Playlist* Playlist::adicionarMusica(Playlist* playlist) {
    string nome;

    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome);

    linkedPlaylist lista = playlist->procurarPlaylist(nome);

    if(!lista.nome.empty()) {
        lista.musicas->adicionar(lista.musicas);
    }else{
        cout << "Ops! Playlist não encontrada!" << endl;
    }

    return playlist;
}

Playlist* Playlist::removerMusica(Playlist* playlist, Musicas* musicas) {
    string nome, titulo;

    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome); 

    linkedPlaylist lista = playlist->procurarPlaylist(nome);

    if(!lista.nome.empty()) {
        cout << "Digite o título da música: ";
        cin >> ws;
        getline(cin,titulo);

        lista.musicas->deletar(titulo);
    }else{
        cout << "Ops! Playlist não encontrada!" << endl;
    }    

    return playlist;
}    

Playlist* Playlist::removerMusica(Playlist* playlist) {
    string nome;

    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome);

    linkedPlaylist lista = playlist->procurarPlaylist(nome);

    if(!lista.nome.empty()) {
        lista.musicas->remover(lista.musicas);
    }else{
        cout << "Ops! Playlist não encontrada!" << endl;
    }

    return playlist;
}

Playlist* Playlist::juntar(Playlist* p1, Playlist p2) {
    string n1, n2, n3;
    cout << "Digite o nome da primeira playlist: ";
    cin >> ws;
    getline(cin,n1); 

    linkedPlaylist primeiraLista = p1->procurarPlaylist(n1);

    if(!primeiraLista.nome.empty()) {
        cout << "Digite o nome da segunda playlist: ";
        cin >> ws;
        getline(cin,n2); 

        linkedPlaylist segundaLista = p1->procurarPlaylist(n2);

        if(!segundaLista.nome.empty()) {
            cout << "Digite o nome da nova playlist: ";
            cin >> ws;
            getline(cin,n3);

            Musicas* musicas = new Musicas();
            musicas = musicas->unirDuasListasMusica(primeiraLista.musicas, segundaLista.musicas);

            p1->adicionar(n3, musicas);
        } 
    }

    return p1;
}

Playlist* Playlist::removerUltimaMusicaPlaylist(Playlist* playlist) {
    string nome;
    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome); 

    linkedPlaylist lista = playlist->procurarPlaylist(nome);

    if(!lista.nome.empty()) {
        linkedPlaylist *novaListaMusicas = new linkedPlaylist;
        Musicas *novaLista = new Musicas();

        novaLista = novaLista->apagarUltimaMusica(lista.musicas);
        novaListaMusicas->musicas = novaLista;

        linkedPlaylist *atual = new linkedPlaylist;
        atual = playlist->cabeca;

        while(atual != NULL) {
            if(atual->nome.compare(nome) == 0) {
                atual->musicas = novaLista;
            }  

            atual = atual->proxima;
        }
    }

    return playlist;
}

Playlist* Playlist::adicionarMusicaUltimaPosicaoPlaylist(Playlist* playlist) {
    string nome;
    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome); 

    linkedPlaylist lista = playlist->procurarPlaylist(nome);

    if(!lista.nome.empty()) {
        linkedPlaylist *novaListaMusicas = new linkedPlaylist;
        Musicas *novaLista = new Musicas();

        novaLista = novaLista->criarMusicaUltimaPosicao(lista.musicas);
        novaListaMusicas->musicas = novaLista;

        linkedPlaylist *atual = new linkedPlaylist;
        atual = playlist->cabeca;

        while(atual != NULL) {
            if(atual->nome.compare(nome) == 0) {
                atual->musicas = novaLista;
            }  

            atual = atual->proxima;
        }
    }    

    return playlist;
}

Playlist* Playlist::copiarPlayListMaisUmaMusica(Playlist* playlist, Musica musica) {
    string nome, novoNome;
    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,nome); 

    linkedPlaylist lista = playlist->procurarPlaylist(nome);

    if(!lista.nome.empty()) {
        cout << "Digite o nome da nova playlist: ";
        cin >> ws;
        getline(cin,novoNome);

        Musicas* musicas = new Musicas();
        musicas = musicas->criar(lista.musicas);

        playlist->adicionar(novoNome, musicas);
    }


    return playlist;
}

Playlist* Playlist::novaPlaylistSemMusicasRepetidas(Playlist* p1, Playlist p2) {
    string n1, n2, n3;
    cout << "Digite o nome da primeira playlist: ";
    cin >> ws;
    getline(cin,n1); 

    linkedPlaylist primeiraLista = p1->procurarPlaylist(n1);

    if(!primeiraLista.nome.empty()) {
        cout << "Digite o nome da segunda playlist: ";
        cin >> ws;
        getline(cin,n2); 

        linkedPlaylist segundaLista = p1->procurarPlaylist(n2);

        if(!segundaLista.nome.empty()) {
            cout << "Digite o nome da nova playlist: ";
            cin >> ws;
            getline(cin,n3);

            Musicas* musicas = new Musicas();
            musicas = musicas->concatenar(primeiraLista.musicas, *segundaLista.musicas);

            p1->adicionar(n3, musicas);
        } 
    }

    return p1;
}

Playlist* Playlist::novaPlaylistMenosUmaMusica(Playlist* playlist, Musica musica) {
    string n1, n2;
    cout << "Digite o nome da playlist: ";
    cin >> ws;
    getline(cin,n1); 

    linkedPlaylist primeiraLista = playlist->procurarPlaylist(n1);

    if(!primeiraLista.nome.empty()) {
        cout << "Digite o nome da nova playlist: ";
        cin >> ws;
        getline(cin,n2);

        Musicas* musicas = new Musicas();
        musicas = musicas->apagar(primeiraLista.musicas);

        playlist->adicionar(n2, musicas);
    }

    return playlist;
}