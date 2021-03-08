#include "musica.h"

// Método responsável por retornar o nome da música
string Musica::getTitulo() {
    return this->titulo;
}

// Método responsável por inserir o nome da música
void Musica::setTitulo(string titulo) {
    this->titulo = titulo;
}

// Método responsável por retornar o nome do autor
string Musica::getAutor() {
    return this->autor;
}

// Método responsável por inserir o nome do autor
void Musica::setAutor(string autor) {
    this->autor = autor;
}