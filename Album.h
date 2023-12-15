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
    Dynarray<Cancion> *canciones = new Dynarray<Cancion>(5);
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
        c.setAlbum(titulo);
        canciones->push(c);
    }

    void mostrarCanciones(){
        if (canciones != nullptr && canciones->size() > 0) {
            cout << "Canciones del album " << getTitulo() << ":" << endl;
            for (int i = 0; i < canciones->size(); ++i) {
                cout << canciones->getFirstelemento()[i].getTitulo() << endl;
            }
        } else {
            cout << "Este album no tiene canciones." << endl;
        }
    }

/*
    void buscarAlbum(string a){
        for (int i = 0; i < canciones->size(); ++i) {
            if (canciones->firstelemento[i].getTitulo() == a || canciones->firstelemento[i].getAlbum() == a ||
            canciones->firstelemento[i].getAutor() == a || canciones->firstelemento[i].getGenero() == a) {
                cout << "El elemento " << a << " se encuentra en la posicion " << i << endl;
                cout << "Titulo: " << canciones->firstelemento[i].getTitulo() << endl;
                cout << "Album: " << canciones->firstelemento[i].getAlbum() << endl;
                cout << "Autor: " << canciones->firstelemento[i].getAutor() << endl;
                cout << "Genero: " << canciones->firstelemento[i].getGenero() << endl;
            }
        }
    }
    */
    void searchGenerico(string generico) {
        bool encontrado = false;
        if (canciones->size() != 0) {
            for (int i = 0; i < canciones->size(); i++) {
                if (canciones->getFirstelemento()[i].getTitulo() == generico ||
                    canciones->getFirstelemento()[i].getAlbum() == generico ||
                    canciones->getFirstelemento()[i].getAutor() == generico ||
                    canciones->getFirstelemento()[i].getGenero() == generico) {
                    cout << "El elemento " << generico << " se encuentra en la posicion " << i << endl;
                    encontrado = true;
                    cout << "Titulo: " << canciones->getFirstelemento()[i].getTitulo() << endl;
                    cout << "Album: " << canciones->getFirstelemento()[i].getAlbum() << endl;
                    cout << "Autor: " << canciones->getFirstelemento()[i].getAutor() << endl;
                    cout << "Genero: " << canciones->getFirstelemento()[i].getGenero() << endl;
                }
            }
        } else {
            cout << "El array esta vacio." << endl;
        }
        if (!encontrado) {
            cout << "El elemento " << generico << " no se encuentra en el album" << endl;
        }
    }
    ~Album() {
        delete canciones;
        canciones = nullptr;
       // cout << "Album deleted" << endl;
    }
};
#endif //GRUPO6_AC3_ALBUM_H
