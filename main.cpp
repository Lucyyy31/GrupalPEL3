#include <iostream>
using namespace std;
void mostrarMenu() {
    cout << "\nMenu del Catalogo:" << endl;
    cout << "1. Canciones" << endl;
    cout << "2. Peliculas" << endl;
    cout << "3. Series" <<endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
/*
 * DynArray<DynArray<Cancion>*> *ListaAlbum = new DynArray<DynArray<Cancion>*>(6);
                    DynArray<Cancion> *a1 = new DynArray<Cancion>(6);
                    DynArray<Cancion> *a2 = new DynArray<Cancion>(6);
                    DynArray<Cancion> *a3 = new DynArray<Cancion>(6);
                    DynArray<Cancion> *a4 = new DynArray<Cancion>(6);
                    ListaAlbum->push(a1);
                    ListaAlbum->push(a2);
                    ListaAlbum->push(a3);
                    ListaAlbum->push(a4);
                    a1->push(Cancion("Cancion1", "Album1", "Autor1", "Genero1"));
                    a2->push(Cancion("Cancion2", "Album2", "Autor2", "Genero2"));
                    a3->push(Cancion("Cancion3", "Album3", "Autor3", "Genero3"));
                    a4->push(Cancion("Cancion4", "Album4", "Autor1", "Genero4"));
                    a2->push(Cancion("Cancion5", "Album2", "Autor2", "Genero5"));
                    a2->push(Cancion("Cancion6", "Album2", "Autor2", "Genero3"));
                    //ListaAlbum->searchDyn("Cancion1");
                    //ListaAlbum[2].searchGenerico("Cancion1");
                    for (int i = 0; i < ListaAlbum->size(); ++i) {
                        ListaAlbum[i].searchGenerico("Cancion1");
                    }
                    cout << "Solo usando el album" << endl;
                    a1->searchGenerico("Cancion1");

 */
int main() {
    int opcion;
    do {
        mostrarMenu();
        while (!(cin >> opcion)){
            cout << "ingrese una opción valida!" << endl;
            cin.clear();
            cin.ignore(40,'\n');
            mostrarMenu();
        };
        switch (opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
    return 0;
}
