//
// Created by lucia on 13/12/2023.
//
#include <iostream>
#ifndef EJERCICIOSTEMA3_CANCION_H
#define EJERCICIOSTEMA3_CANCION_H
using namespace std;
class Cancion{
private:
    string titulo;
    string album;
    string autor;
    string genero;
public:
    Cancion(){
        Cancion::titulo = "";
        Cancion::album = "";
        Cancion::autor = "";
        Cancion::genero = "";
    }
    Cancion(string t, string a, string au, string g){
        Cancion::titulo = t;
        Cancion::album = a;
        Cancion::autor = au;
        Cancion::genero = g;
    }
    string getTitulo(){
        return titulo;
    }
    string getAlbum(){
        return album;
    }
    string getAutor(){
        return autor;
    }
    string getGenero(){
        return genero;
    }

};
#endif //EJERCICIOSTEMA3_CANCION_H
