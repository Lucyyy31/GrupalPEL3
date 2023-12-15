#include <iostream>
#include <cstdlib>  // Necesario para la función rand()
#include "Cancion.h"
#include "DynArray.h"
#include "Album.h"
using namespace std;

/// @brief un metodo que permite obtener un input del tipo T, con un mensaje de error y un limite de intentos
/// @tparam T el tipo de dato que se quiere asegurar que sea el input
/// @param promptInicial el mensaje inicial a mostrarse para pedir un input
/// @param promptError el mensaje que se muestra si el intento es invalido
/// @param maxIntentos el numero maximo de intentos permitidos. cualquier numero <=0 se considera infinito. si se llega al limite, se retorna un valor por defecto del tipo T
/// @return el input del tipo T o un valor por defecto del tipo T si se llega al limite de intentos
template <typename T>
T getInput(const string promptInicial, const string promptError, int maxIntentos)
{
    if (maxIntentos == 0)
        maxIntentos--;
    T out;
    cout << promptInicial << endl;
    cin >> out;
    while (!cin.good() && maxIntentos != 0)
    {
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << promptError << endl;
        cin >> out;
    }
    if (maxIntentos == 0)
    {
        return T();
    }

    return out;
}

/// @brief un metodo que permite obtener un input del tipo T, con un mensaje de error, un limite de intentos y una funcion que evalua si el input es valido
/// @tparam T el tipo de dato que se quiere asegurar que sea el input
/// @param promptInicial el mensaje inicial a mostrarse para pedir un input
/// @param promptError el mensaje que se muestra si el intento es invalido
/// @param maxIntentos el numero maximo de intentos permitidos. cualquier numero <=0 se considera infinito
/// @param eval una funcion que evalua si el input es valido según un criterio propio
/// @return el input del tipo T,que cumple con la condición de eval, o un valor por defecto del tipo T si se llega al limite de intentos
template <typename T>
T getInput(string promptInicial, string promptError, int maxIntentos, function<bool(T)> eval)
{
    if (maxIntentos == 0)
        maxIntentos--;
    T out;
    cout << promptInicial << endl;
    cin >> out;
    bool cont = false;
    bool exempt = false;
    try
    {
        eval(T());
        exempt = false;
    }
    catch (...)
    {
        exempt = true;
    }
    while (!cont)
    {
        while (!cin.good() && maxIntentos-- != 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << promptError << endl;
            cin >> out;
        }
        // tengo un valor del tipo correcto, no sé si es apropiado según eval
        if (!exempt)
        {
            // la funcion eval no aplica
            if (eval(out))
            {
                cont = true;
            }

            // ahora se si pasa la condición. si no pasa, quiero volver a preguntar, es decir no cambio la condicion de escape
            else
            {
                cout << promptError << endl;
                cin >> out;
            }
        }
        else
            cont = true;
    }
    if (maxIntentos == 0)
    {
        return T();
    }
    return out;
}
bool isNotEmpty(string s){
    return s != "";
}

void mostrarMenu() {
    cout << "\nMenu del Catalogo:" << endl;
    cout << "1. Canciones" << endl;
    cout << "2. Contenido audiovisual" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
void menuMusica(Dynarray<Album> * albumes) {
    cout << "Menu musica:" << endl;
    cout << "1. Mostrar canciones" << endl;
    cout << "2. Mostrar albumes" << endl;

    cout << "Ingrese el numero de la opcion: ";
    int opcionMusica;
    cin >> opcionMusica;
    switch (opcionMusica) {
        case 1:
            cout << "Canciones:" << endl;
            cout << "1. Mostrar todas las canciones" << endl;
            cout << "2. Buscar canciones" << endl;
            cout << "3. Salir" << endl;
            cout << "Ingrese el numero de la opcion: ";
            int opcionCanciones;
            cin >> opcionCanciones;
            switch (opcionCanciones) {
                case 1:
                    cout << "Mostrando todas las canciones:" << endl;
                    for (int i = 0; i < albumes->size(); ++i) {
                        albumes->getFirstelemento()[i].mostrarCanciones();
                    }
                    break;
                case 2:
                    cout << "Buscando canciones:" << endl;
                    {
                        string genericoBuscado;
                        cout << "Ingrese el autor, genero, nombre o album a buscar: ";
                        cin.ignore();
                        getline(cin, genericoBuscado);

                        for (int i = 0; i < albumes->size(); ++i) {
                            albumes->getFirstelemento()[i].searchGenerico(genericoBuscado);
                        }
                    }
                    break;
                case 3:
                    cout << "Saliendo del menu de canciones." << endl;
                    break;
                default:
                    cout << "Opción no válida. Intente de nuevo." << endl;
            }
            break;
        case 2:
            cout << "Albumes:" << endl;
            cout << "1. Mostrar todos los albumes" << endl;
            cout << "2. Buscar albumes" << endl;
            cout << "3. Salir" << endl;
            cout << "Ingrese el numero de la opcion: ";
            int opcionAlbumes;
            cin >> opcionAlbumes;
            switch (opcionAlbumes) {
                case 1:
                    cout << "Mostrando todos los albumes:" << endl;
                    albumes->mostrarTodo();
                    break;
                case 2: {
                    cout << "Buscando albumes:" << endl;
                    string genericoBuscado;
                    cout << "Ingrese el autor, genero o nombre a buscar: ";
                    cin.ignore();
                    getline(cin, genericoBuscado);

                    for (int i = 0; i < albumes->size(); ++i) {
                        albumes->getFirstelemento()[i].searchGenerico(genericoBuscado);
                    }
                }
                    break;
                case 3:
                    cout << "Saliendo del menu de album" << endl;
                    break;
                default:
                    cout << "Opción no válida. Intente de nuevo." << endl;

            }
    }

}

int main() {
    int opcion;
    srand(time(NULL));
    do {
        mostrarMenu();
        while (!(cin >> opcion)) {
            cout << "ingrese una opcion valida!" << endl;
            cin.clear();
            cin.ignore(40, '\n');
            mostrarMenu();
        };
        switch (opcion) {
            case 1: {
                Dynarray<Cancion> *canciones = new Dynarray<Cancion>(5);
                Dynarray<Album> *albumes = new Dynarray<Album>(5);
                Album album1("Album1", "Autor1", "Genero1");
                Album album2("Album2", "Autor2", "Genero2");
                Album album3("Album3", "Autor3", "Genero3");
                albumes->push(album1);
                albumes->push(album2);
                albumes->push(album3);
                string nombresAlbumes[] = {"Album1", "Album2", "Album3"};
                string nombresCanciones[] = {"Cancion1", "Cancion2", "Cancion3", "Cancion4", "Cancion5",
                                             "Cancion6", "Cancion7", "Cancion8", "Cancion9", "Cancion10"};
                string nombresAutores[] = {"Autor1", "Autor2", "Autor3"};
                string nombresGeneros[] = {"Genero1", "Genero2", "Genero3"};

                for (int i = 0; i < 10; ++i) {
                    string nombreAlbum = nombresAlbumes[rand() % 3];
                    string nombreCancion = nombresCanciones[rand() % 10];
                    string nombreAutor = nombresAutores[rand() % 3];
                    string nombreGenero = nombresGeneros[rand() % 3];
                    Cancion cancion(nombreCancion, nombreAutor, nombreGenero);
                    bool cancionAgregada = false;
                    for (int j = 0; j < albumes->size(); ++j) {
                        if (albumes->getFirstelemento()[j].getTitulo() == nombreAlbum) {
                            // Verificar si la canción ya está en el álbum
                            if (albumes->getFirstelemento()[j].perteneceAlbum(cancion) && cancion.getTitulo() == nombreCancion) {
                                cancionAgregada = true;
                            }
                        }
                    }
                    if (!cancionAgregada) {
                        if (cancion.getAutor() == album1.getAutor()) {
                            album1.addCancion(cancion);
                            cancion.setAlbum(album1.getTitulo());
                            canciones->push(cancion);
                        } else if (cancion.getAutor() == album2.getAutor()) {
                            album2.addCancion(cancion);
                            cancion.setAlbum(album2.getTitulo());
                            canciones->push(cancion);
                        } else if (cancion.getAutor() == album3.getAutor()) {
                            album3.addCancion(cancion);
                            cancion.setAlbum(album3.getTitulo());
                            canciones->push(cancion);
                        }
                    }
                }
                if (albumes->isEmpty()) {
                    cout << "No hay albumes." << endl;
                } else {
                    menuMusica(albumes);
                }
                    break;
                }
                case 2:
                    string prompt = "Menu contenido audiovisual:\n1. Mostrar series/peliculas\n2. Buscar serie/pelicula\n3. Modificar catalogo\n4. Salir\nIngrese el numero de la opcion: ";
                    string promptError = "Ingrese una opcion valida!";
                    int pick =0,pick2=0;
                    while(pick!=4){
                        pick2=0;
                     pick = getInput<int>(prompt, promptError, 0, [](int x) { return x > 0 && x < 5; });
                     switch(pick){
                        case 1:
                        prompt = "1. Mostrar todas las series\n2. Mostrar todas las peliculas\n3. Mostrar todas las series y peliculas\nIngrese el numero de la opcion: ";
                        pick2 = getInput<int>(prompt, promptError, 0, [](int x) { return x > 0 && x < 4; });
                        Vector<ContenidoAV*> contenido = catalogo.getContenido();
                        if(pick2!=2){
                            for(Pelicula* pelicula: contenido.getPeliculas()){
                                cout << *pelicula << endl;
                            }
                        }
                        if(pick2!=1){
                            for(Serie* serie: contenido.getSeries()){
                                cout << *serie << endl;
                            }
                        }
                        break;
                        case 2:
                        //create an array of the member functions of catalogo that return a vector of ContenidoAV*
                        (Vector<ContenidoAV*> (Catalogo::*) (string)) catalogoFuncs[] = {&Catalogo::getContenidoByTitulo, &Catalogo::getContenidoByGenero, &Catalogo::getContenidoByCalidad};
                        prompt = "1. Buscar por titulo\n2. Buscar por genero\n3. Buscar por calidad\nIngrese el numero de la opcion: ";
                        pick2 = getInput<int>(prompt, promptError, 0, [](int x) { return x > 0 && x < 4; });
                        prompt = "Ingrese el titulo, genero o calidad a buscar: ";
                        string genericoBuscado = getInput<string>(prompt, promptError, 0);
                        Vector<ContenidoAV*> contenidoBuscado = (catalogo.*catalogoFuncs[pick2-1])(genericoBuscado);
                        if(contenidoBuscado.size() == 0){
                            cout << "No se encontró el contenido" << endl;
                        }
                        else{
                            for(ContenidoAV* contenido: contenidoBuscado){
                                cout << *contenido << endl;
                            }
                        }
                        break;
                        case 3:
                        prompt = "1. Agregar contenido\n2. Eliminar contenido\nIngrese el numero de la opcion: ";
                        pick2 = getInput<int>(prompt, promptError, 0, [](int x) { return x > 0 && x < 3; });
                        bool makeUHD, makePPV, serie;
                        string titulo, genero;
                        float ppvPrice;
                        int typeSpecific;
                        serie = getInput<string>("Es una serie o pelicula?: ", promptError, 0,[&](string x){return x == "serie" || x == "pelicula";}) == "serie";
                        titulo = getInput<string>("Ingrese el titulo: ", promptError, 0, isNotEmpty);
                        genero = getInput<string>("Ingrese el genero: ", promptError, 0, isNotEmpty);
                        makeUHD = getInput<string>("Es UHD?(si/no): ", promptError, 0, [](string x){return x == "si" || x == "no";}) == "si";
                        if(serie){
                            typeSpecific = getInput<int>("Ingrese el numero de episodios: ", promptError, 0, [](int x){return x > 0;});
                        }
                        else{
                            typeSpecific = getInput<int>("Ingrese la duracion en minutos: ", promptError, 0, [](int x){return x > 0;});
                        }
                        makePPV = getInput<string>("Está incluido en la tarifa basica?(si/no): ", promptError, 0, [](string x){return x == "si" || x == "no";}) == "si";
                        if(makePPV){
                            ppvPrice = getInput<float>("Ingrese el costo adicional: ", promptError, 0, [](float x){return x > 0;});
                        }
                        if(serie){
                            if(makePPV){
                                catalogo.addContenido(new Serie(titulo, genero, makeUHD, makePPV, ppvPrice, typeSpecific));
                            }
                            else{
                                catalogo.addContenido(new Serie(titulo, genero, makeUHD, typeSpecific));
                            }
                        }
                        else{
                            if(makePPV){
                                catalogo.addContenido(new Pelicula(titulo, genero, makeUHD, makePPV, ppvPrice, typeSpecific));
                            }
                            else{
                                catalogo.addContenido(new Pelicula(titulo, genero, makeUHD, typeSpecific));
                            }
                        }
                        break;
                        
                     }
                    }

                    break;
                case 3:
                    cout << "Saliendo del programa." << endl;
                break;
                default:
                    cout << "Opcion no valida. Intente de nuevo." << endl;
            }
        }
        while (opcion != 4);
        return 0;
    }
