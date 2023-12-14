//
// Created by lucia on 14/12/2023.
//

#ifndef GRUPO6_AC3_ALBUM_H
#define GRUPO6_AC3_ALBUM_H
using namespace std;
#include "Cancion.h"
#include "DynArray.h"

class Album{
private:
    string titulo;
    string autor;
    string genero;
    Dynarray<Cancion> *canciones;
public:
    Album(){
        titulo = "";
        autor = "";
        genero = "";
    }
    Album(string t, string a, string g){
        titulo = t;
        autor = a;
        genero = g;
    }
    string getTitulo(){
        return titulo;
    }
    string getAutor(){
        return autor;
    }
    string getGenero(){
        return genero;
    }
    void addCancion(Cancion c){
        canciones->insert(c);
    }
    void mostrarCanciones(){
        for (int i = 0; i < canciones->count; ++i) {
            cout << canciones->first[i].getTitulo() << endl;
        }
    }

    void buscarAlbum(string a){
        for (int i = 0; i < canciones->count; ++i) {
            if (canciones->first[i].getAutor() == a){
                cout << canciones->first[i].getTitulo() << endl;
            }
        }
    }

};
#endif //GRUPO6_AC3_ALBUM_H
