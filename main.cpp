#include <iostream>
#include "Cancion.h"
#include "DynArray.h"
#include "Album.h"

using namespace std;
void mostrarMenu() {
    cout << "\nMenu del Catalogo:" << endl;
    cout << "1. Canciones" << endl;
    cout << "2. Peliculas" << endl;
    cout << "3. Series" <<endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
void menuMusica() {
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
            cout << "2. Buscar canciones por autor" << endl;
            cout << "3. Buscar canciones por genero" << endl;
            cout << "4. Salir" << endl;
            cout << "Ingrese el numero de la opcion: ";
            int opcionCanciones;
            cin >> opcionCanciones;
            switch (opcionCanciones) {
                case 1:
                    cout << "Mostrando todas las canciones:" << endl;

                    break;
                case 2:
                    cout << "Buscando canciones por autor:" << endl;
                    break;
                case 3:
                    cout << "Buscando canciones por genero:" << endl;
                    break;
                case 4:
                    cout << "Saliendo del menu de canciones." << endl;
                    break;
                default:
                    cout << "Opción no válida. Intente de nuevo." << endl;
            }
            break;
        case 2:
            cout << "Albumes:" << endl;
            cout << "1. Mostrar todos los albumes" << endl;
            cout << "2. Buscar albumes por autor" << endl;
            cout << "3. Buscar albumes por genero" << endl;
            cout << "4. Salir" << endl;
            cout << "Ingrese el numero de la opcion: ";
            int opcionAlbumes;
            cin >> opcionAlbumes;
            switch (opcionAlbumes) {
                case 1:
                    cout << "Mostrando todos los albumes:" << endl;
                    break;
                case 2:
                    cout << "Buscando albumes por autor:" << endl;
                    break;
                case 3:
                    cout << "Buscando albumes por genero:" << endl;
                    break;
                case 4:
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
        while (!(cin >> opcion)){
            cout << "ingrese una opcion valida!" << endl;
            cin.clear();
            cin.ignore(40,'\n');
            mostrarMenu();
        };
        switch (opcion) {
            case 1:{
                Dynarray<Cancion> *canciones = new Dynarray<Cancion>(5);
                Dynarray<Album> *albumes = new Dynarray<Album>(5);
                Cancion cancion1("Cancion1", "Autor1", "Genero1");
                Cancion cancion2("Cancion2", "Autor2", "Genero2");
                Cancion cancion3("Cancion3", "Autor3", "Genero3");

                canciones->insert(cancion1);
                canciones->insert(cancion2);
                canciones->insert(cancion3);

                Album album1("Album1", "Autor1", "Genero1");
                album1.addCancion(cancion1);
                album1.addCancion(cancion2);
                album1.addCancion(cancion3);
                albumes->insert(album1);
                menuMusica();
                break;}
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
    } while (opcion != 4);
    return 0;
}