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

                    break;
                case 3:

                    break;
                case 4:
                    cout << "Saliendo del programa." << endl;
                break;
                default:
                    cout << "Opcion no valida. Intente de nuevo." << endl;
            }
        }
        while (opcion != 4);
        return 0;
    }
