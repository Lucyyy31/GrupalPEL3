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
                contenido.removeElementAt(i);
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

/// @brief Busca todos los ContenidoAV(serie o pelicula) en el catalogo con un determinado titulo
/// @param titulo Titulo del ContenidoAV a buscar
/// @return Vector de punteros a ContenidoAV encontrados
Vector<ContenidoAV*> getContenidoByTitulo(string titulo){
    Vector<ContenidoAV*> result;
    for(int i = 0; i < contenido.size(); i++){
        if(contenido[i]->getTitulo() == titulo){
            result.push_back(contenido[i]);
        }
    }
    return result; // retorna el vector de contenidos encontrados
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

     Vector<ContenidoAV*> getContenidoByCalidad(string calidad){
        bool UHD = (calidad == "UHD")|| (calidad == "uhd");
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


    /// @brief permite obtener todas las series del catalogo
    /// @return un vector de punteros a series
    Vector<Serie*> getSeries(){
        Vector<Serie*> contenidoSeries;
        string idSerie=typeid(Serie).name();
        for(int i = 0; i < contenido.size(); i++){
            if(typeid(*contenido[i]).name()==idSerie){
                Serie* serie = dynamic_cast<Serie*>(contenido[i]);
                if(serie != nullptr){
                    contenidoSeries.push_back(serie);
                }
            }
        }
        return contenidoSeries;
    }

    /// @brief permite obtener todas las peliculas del catalogo
    /// @return un vector de punteros a peliculas
    Vector<Pelicula*> getPeliculas(){
        Vector<Pelicula*> contenidoPeliculas;
        string idPelicula=typeid(Pelicula).name();
        for(int i = 0; i < contenido.size(); i++){
            if(typeid(*contenido[i]).name()==idPelicula){
                Pelicula* pelicula = dynamic_cast<Pelicula*>(contenido[i]);
                if(pelicula != nullptr){
                    contenidoPeliculas.push_back(pelicula);
                }
            }
        }
        return contenidoPeliculas;
    }

    /// @brief Sobrecarga del operador << para imprimir el catalogo
    /// @param os el flujo de salida ( buffer de texto)
    /// @param catalogo el objeto
    /// @return el flujo de salida modificado para tener la informacion concatenada a él
    friend ostream& operator<<(ostream& os, const Catalogo& catalogo){
        os << "Catalogo" << endl;
        for(int i = 0; i < catalogo.contenido.size(); i++){
            os << catalogo.contenido[i]->getTitulo() << endl;
        }
        return os;
    }

    //destructor
    ~Catalogo(){
        for(int i = 0; i < contenido.size(); i++){
            delete contenido[i];
        }
    }
};
#endif //GRUPO6_AC3_CATALOGO_H