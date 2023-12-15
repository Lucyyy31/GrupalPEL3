#ifndef GRUPO6_AC3_CONTENIDOAV_H
#define GRUPO6_AC3_CONTENIDOAV_H
#include <iostream>
using namespace std;
class ContenidoAV {
private: 
    string titulo, genero; 
    float ppvPrice;
    bool isUHD, isPPV,available;
public:
    ContenidoAV()=default;
    ContenidoAV(string titulo, string genero, bool isUHD, bool isPPV, float ppvPrice){
        ContenidoAV::titulo = titulo;
        ContenidoAV::genero = genero;
        ContenidoAV::isUHD = isUHD;
        ContenidoAV::isPPV = isPPV;
        if(isPPV){
            ContenidoAV::ppvPrice = ppvPrice;
        }
        else{
            ContenidoAV::ppvPrice = 0;
        }
    }
    ContenidoAV(string titulo, string genero, bool isUHD){
        ContenidoAV::titulo = titulo;
        ContenidoAV::genero = genero;
        ContenidoAV::isUHD = isUHD;
        ContenidoAV::isPPV = false;
        ContenidoAV::ppvPrice = 0;
    }
    string getTitulo() const {
        return titulo;
    }
    string getGenero() const {
        return genero;
    }
    bool IsUHD() const {
        return isUHD;
    }
    bool IsPPV() const {
        return isPPV;
    }
    float getPpvPrice() const {
        return ppvPrice;
    }
    bool isAvailable() const {
        return available;
    }
    void setAvailable(bool available) {
        ContenidoAV::available = available;
    }

    friend ostream& operator<<(ostream& os, const ContenidoAV& contenidoAV){
        os << "Contenido AV" << endl;
        os << "Titulo: " << contenidoAV.getTitulo() << endl;
        os << "Genero: " << contenidoAV.getGenero() << endl;
        os << "Calidad: " << (contenidoAV.IsUHD()?"UHD":"FHD") << endl;
        os << "incluido con la tarifa basica?: " << (contenidoAV.IsPPV()?"no":"si") << endl;
        if(contenidoAV.IsPPV()){
            os << "Precio PPV: " << contenidoAV.getPpvPrice() << endl;
        }
        return os;
    }

    virtual ~ContenidoAV()=default;
}; 

class Pelicula: public ContenidoAV{
private:
    int duracion;
public:
    Pelicula()=default;
    Pelicula(string titulo, string genero, bool isUHD, bool isPPV, float ppvPrice, int duracion):ContenidoAV(titulo,genero,isUHD,isPPV,ppvPrice){
        Pelicula::duracion = duracion;
    }
    Pelicula(string titulo, string genero, bool isUHD, int duracion):ContenidoAV(titulo,genero,isUHD){
        Pelicula::duracion = duracion;
    }
    int getDuracion() const {
        return duracion;
    }

    friend ostream& operator<<(ostream& os, const Pelicula& pelicula){
        os << "Pelicula" << endl;
        os << "Titulo: " << pelicula.getTitulo() << endl;
        os << "Genero: " << pelicula.getGenero() << endl;
        os << "Duracion: " << pelicula.getDuracion() << endl;
        os << "Calidad: " << (pelicula.IsUHD()?"UHD":"FHD") << endl;
        os << "incluido con la tarifa basica?: " << (pelicula.IsPPV()?"no":"si" )<< endl;
        if(pelicula.IsPPV()){
            os << "Precio PPV: " << pelicula.getPpvPrice() << endl;
        }
        return os;
    }

    ~Pelicula()=default;
};

class Serie: public ContenidoAV{
private:
    int numEpisodios;
public:
    Serie()=default;
    Serie(string titulo, string genero, bool isUHD, bool isPPV, float ppvPrice, int numEpisodios):ContenidoAV(titulo,genero,isUHD,isPPV,ppvPrice){
        Serie::numEpisodios = numEpisodios;
    }
    Serie(string titulo, string genero, bool isUHD, int numEpisodios):ContenidoAV(titulo,genero,isUHD){
        Serie::numEpisodios = numEpisodios;
    }
    int getNumEpisodios() const {
        return numEpisodios;
    }

    friend ostream& operator<<(ostream& os, const Serie& serie){
        os << "Serie" << endl;
        os << "Titulo: " << serie.getTitulo() << endl;
        os << "Genero: " << serie.getGenero() << endl;
        os << "Numero de episodios: " << serie.getNumEpisodios() << endl;
        os << "Calidad: " << (serie.IsUHD()?"UHD":"FHD" )<< endl;
        os << "incluido con la tarifa basica?: " << (serie.IsPPV()?"no":"si") << endl;
        if(serie.IsPPV()){
            os << "Precio PPV: " << serie.getPpvPrice() << endl;
        }
        return os;
    }

    ~Serie()=default;
};





#endif //GRUPO6_AC3_VECTOR_H