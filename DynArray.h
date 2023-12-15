//
// Created by lucia on 14/12/2023.
//
#include <iostream>
#ifndef GRUPO6_AC3_DYNARRAY_H
#define GRUPO6_AC3_DYNARRAY_H
using namespace std;

template <typename T>
class Dynarray {
private:
    T* firstelemento; //puntero al primer elemento
    int contador; //numero de elementos guardados
    size_t max; //final del array
public:
    //Constructor para definir tamaño del array y uno vacío para definirlo después
    Dynarray(): firstelemento(nullptr), contador(0) , max(1){}
    Dynarray(size_t n): firstelemento(new T[n]), contador(0), max(n){}

    //Agregar elementos al array
    void push(T& e){
        if (contador >= max){
            max = max*2; //Duplicar tamaño del array
            T* aux = new T[max]; //Crear array auxiliar
            for (int i = 0; i < contador; i++){ // al estar lleno de igual si se usa max o contador
                aux[i] = firstelemento[i]; //Copiar elementos del array original al auxiliar
            }
            delete[] firstelemento; //Borrar elementos del array original
            firstelemento = aux; //Asignar array auxiliar al original
        }
        firstelemento[contador] = e;
        contador++;
    }

    void toString(){
        for (int i = 0; i < contador; ++i) {
            cout<<firstelemento[i]<<" ";
        }
        cout<<" "<<endl;
    }

    // Sacar un elemento del array
    void pop(int indice){
        if(contador != 0){
            if (indice <= contador){
                T* aux = new T[max]; //Crear array auxiliar
                int j = 0;
                for (int i = 0; i < contador; i++){
                    if(i != indice){
                        aux[j] = firstelemento[i]; //Copiar elementos del array original al auxiliar
                        j++;
                    }
                }
                delete [] firstelemento;
                firstelemento = aux;
                contador--;
            }
        }
    }
    void search(T e){
        bool encontrado = false;
        if(contador != 0 ){
            for(int i = 0; i < contador; i++){
                if(firstelemento[i] == e){
                    cout << "El elemento " << e << " se encuentra en la posicion " << i << endl;
                    encontrado = true;
                }
            }
        }else{
            cout<<"El array está vacio." <<endl;
        }
        if(!encontrado){
            cout << "El elemento " << e << " no se encuentra en el array" << endl;
        }

    }
    int size(){
        return contador;
    }
    void print() {
        for (int i = 0; i < contador; ++i) {
            cout << firstelemento[i] << endl;
        }
    };
    bool isEmpty() const {
        return contador == 0;
    };
    //destructores
    ~Dynarray() {
        delete[] Dynarray::firstelemento;
       // cout << "Dynarray deleted" << endl;
    };
    void mostrarTodo(){
        for (int i = 0; i < size(); ++i) {
            cout << firstelemento[i].getTitulo() << endl;
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
    void searchDyn(string generico) {
        for (int i = 0; i < contador; ++i) {
            firstelemento[i]->searchGenerico(generico);
        }
    }
    auto operator[](size_t i){
        if(i<contador){
            return firstelemento[i];
        }
    }
    T* getFirstelemento(){
        return firstelemento;
    }
};

#endif //GRUPO6_AC3_DYNARRAY_H
