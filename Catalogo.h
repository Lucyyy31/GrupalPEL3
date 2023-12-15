#ifndef GRUPO6_AC3_CATALOGO_H
#define GRUPO6_AC3_CATALOGO_H
#include <iostream>
#include "ContenidoAV.h"
#include "Vector.h"
using namespace std;
class Catalogo {
private:
    Vector<ContenidoAV*> contenido;
public:
    Catalogo()=default;

/// @brief Constructor de la clase Catalogo
/// @param contenido Vector de ContenidoAV preexistente
    Catalogo(Vector<ContenidoAV*> contenido){
        Catalogo::contenido = contenido;
    }

/// @brief Agrega un ContenidoAV(serie o pelicula) al vector contenido
/// @param contenidoAV ContenidoAV a agregar
    void addContenido(ContenidoAV* contenidoAV){
        contenido.push_back(contenidoAV);
    }

/// @brief Elimina un ContenidoAV(serie o pelicula) del vector contenido
/// @param titulo Titulo del ContenidoAV a eliminar
    void removeContenido(string titulo){
        bool found = false;
        for(int i = 0; i < contenido.size(); i++){
            if(contenido[i]->getTitulo() == titulo){
                contenido.erase(i);
                found = true;
            }
        }
        if(!found){
            cout << "No se encontró el contenido" << endl;
        }
        else{
            cout << "Contenido eliminado con exito" << endl;
        }
    }

/// @brief Busca un ContenidoAV(serie o pelicula) en el vector contenido
/// @param titulo Titulo del ContenidoAV a buscar
/// @return puntero al ContenidoAV encontrado
    ContenidoAV* getContenido(string titulo){
        for(int i = 0; i < contenido.size(); i++){
            if(contenido[i]->getTitulo() == titulo){
                return contenido[i];
            }
        }
        return nullptr; // no se encontró el contenido
    }

/// @brief Busca un ContenidoAV(serie o pelicula) en el vector contenido
/// @param genero Genero del ContenidoAV a buscar
    Vector<ContenidoAV*> getContenidoByGenero(string genero){
        Vector<ContenidoAV*> contenidoGenero;
        for(int i = 0; i < contenido.size(); i++){
            if(contenido[i]->getGenero() == genero){
                contenidoGenero.push_back(contenido[i]);
            }
        }
        return contenidoGenero;
    }
    Vector<ContenidoAV*> getContenidoByCalidad(bool UHD){
        Vector<ContenidoAV*> contenidoUHD;
        for(int i = 0; i < contenido.size(); i++){
            if(contenido[i]->IsUHD()==UHD){
                contenidoUHD.push_back(contenido[i]);
            }
        }
        return contenidoUHD;
    }


    Vector<ContenidoAV*> getContenidoByPPV(){
        Vector<ContenidoAV*> contenidoPPV;
        for(int i = 0; i < contenido.size(); i++){
            if(contenido[i]->IsPPV()){
                contenidoPPV.push_back(contenido[i]);
            }
        }
        return contenidoPPV;
    }
    Vector<ContenidoAV*> getContenidoDisponible(){
        Vector<ContenidoAV*> contenidoAvailable;
        for(int i = 0; i < contenido.size(); i++){
            if(contenido[i]->isAvailable()){
                contenidoAvailable.push_back(contenido[i]);
            }
        }
        return contenidoAvailable;
    }

};
#endif //GRUPO6_AC3_CATALOGO_H