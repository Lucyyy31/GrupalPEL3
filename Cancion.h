//
// Created by lucia on 13/12/2023.
//
#include <iostream>
#ifndef GRUPO6_AC3_CANCION_H
#define GRUPO6_AC3_CANCION_H
using namespace std;
class Cancion{
private:
    string titulo;
    string autor;
    string genero;
    string album;
public:
    Cancion(){
        titulo = "";
        autor = "";
        genero = "";
    }
    Cancion(string t, string a, string g){
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

    void buscarCancion(string a){
        if (autor == a){
            cout << titulo << endl;
        }
    }


};
#endif //GRUPO6_AC3_CANCION_H
