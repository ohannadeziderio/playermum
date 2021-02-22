#ifndef MUSICA_H
#define MUSICA_H
#include <string>

using namespace std;

// Entidade responsável por definir uma música
class Musica {
    private:
        string titulo;
        string autor;
    public:
        Musica() {

        }

        Musica(string titulo, string autor) {
            this->titulo = titulo;
            this->autor = autor;
        }

        // Gets e sets
        string getTitulo();

        void setTitulo(string titulo);

        string getAutor();
        
        void setAutor(string autor);
};

#endif