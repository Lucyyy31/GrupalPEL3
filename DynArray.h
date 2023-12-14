//
// Created by lucia on 14/12/2023.
//
#include <iostream>
#ifndef GRUPO6_AC3_DYNARRAY_H
#define GRUPO6_AC3_DYNARRAY_H
using namespace std;

//Hacer una función que recorra una DynArray que contiene otros DynArrays y usar la funcion searchGenerico para buscar un elemento en todos los DynArrays
void searchDyn(string generico) {
    for (int i = 0; i < contador; ++i) {
        firstelemento[i]->searchGenerico(generico);
    }
}

void searchGenerico(string generico) {
    bool encontrado = false;
    if (contador != 0) {
        for (int i = 0; i < contador; i++) {
            if (firstelemento[i]->getTitulo() == generico || firstelemento[i]->getAlbum() == generico || firstelemento[i]->getAutor() == generico || firstelemento[i]->getGenero() == generico) {
                cout << "El elemento " << generico << " se encuentra en la posicion " << i << endl;
                encontrado = true;
                cout << "Titulo: " << firstelemento[i]->getTitulo() << endl;
                cout << "Album: " << firstelemento[i]->getAlbum() << endl;
                cout << "Autor: " << firstelemento[i]->getAutor() << endl;
                cout << "Genero: " << firstelemento[i]->getGenero() << endl;
            }
        }
    } else {
        cout << "El array esta vacio." << endl;
    }
    if (!encontrado) {
        cout << "El elemento " << generico << " no se encuentra en el album" << endl;
    }

}
auto operator[](size_t i){
    if(i<contador){
        return firstelemento[i];
    }
    else
        //throw
        return nullptr;
}
#endif //GRUPO6_AC3_DYNARRAY_H
