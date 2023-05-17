#include <iostream>
#include <conio.h>
#include "ListaEnlazada.h"

using namespace std;

int main() {
    Lista<int>* lst = new Lista<int>();
    short opc, aux1, aux2;
    bool existe;
    //Uso de lambdas prro >:v
    auto imprimirEstado = [](bool existe) {
        if (existe) {
            cout << "Existente" << endl;
        }
        else {
            cout << "No existente" << endl;
        }
    };

    do {
        do {
            system("cls");
            cout << "1. Agregar elemento al inicio" << endl;
            cout << "2. Agregar elemento (indicando posicion)" << endl;
            cout << "3. Agregar elemento al final" << endl;
            cout << "4. Modificar elemento inicial" << endl;
            cout << "5. Modificar elemento (indicando posicion)" << endl;
            cout << "6. Modificar elemento final" << endl;
            cout << "7. Eliminar elemento inicial" << endl;
            cout << "8. Eliminar elemento (indicando posicion)" << endl;
            cout << "9. Eliminar elemento final" << endl;
            cout << "10. Mostrar elementos" << endl;
            cout << "11. Verificar existencia de numero en lista" << endl;
            cout << "12. Salir del programa" << endl;
            cout << "\t/>"; cin >> opc;
        } while (!(opc >= 1 && opc <= 12));
        switch (opc) {
            case 1:
                cout << "\n\nIngrese elemento incial: "; cin >> aux1;
                lst->agregaInicial(aux1);
                break;
            case 2: 
                cout << "\nIngrese elemento: "; cin >> aux1;
                do {
                    cout << "\nIngrese posicion en el rango (0," << lst->longitud() - 1 << ")"; cin >> aux2;
                } while (!(aux2 > 0 && aux2 < lst->longitud() - 1));
                lst->agregaPos(aux1, aux2);
                break;
            case 3: 
                cout << "\n\nIngrese elemento final: "; cin >> aux1;
                lst->agregaFinal(aux1);
                break;
            case 4: 
                cout << "\n\nIngrese nuevo elemento inicial: "; cin >> aux1;
                lst->modificarInicial(aux1);
                break;
            case 5: 
                do {
                    cout << "\nIngrese posicion en el rango (0," << lst->longitud() - 1 << ")"; cin >> aux2;
                } while (!(aux2 > 0 && aux2 < lst->longitud() - 1));
                cout << "\nIngrese nuevo elemento: "; cin >> aux1;
                lst->modificarPos(aux1, aux2);
                break;
            case 6: 
                cout << "\n\nIngrese nuevo elemento final: "; cin >> aux1;
                lst->modificarFinal(aux1);
                break;
            case 7: 
                cout << "\n\nEliminando elemento inicial... ";
                lst->eliminaInicial();
                _sleep(500);
                break;
            case 8: 
                do {
                    cout << "\nIngrese posicion en el rango (0," << lst->longitud() - 1 << ")"; cin >> aux1;
                } while (!(aux1 > 0 && aux1 < lst->longitud() - 1));
                lst->eliminaPos(aux1);
                cout << "\nEliminando elemento en la posicion " << aux1 << "...";
                _sleep(500);
                break;
            case 9: 
                cout << "\n\nEliminando elemento final... ";
                lst->eliminaFinal();
                _sleep(500); 
                break;
            case 10: 
                cout << "\nLongitud de la lista " << lst->longitud() << endl;
                for (int i = 0; i < lst->longitud(); i++) {
                    cout << "Elemento " << i + 1 << ": " << lst->obtenerPos(i) << endl;
                }
                if (lst->esVacia()) {
                    cout << "\n\nNingun elemento existente en la lista!!" << endl;
                }
                system("pause>null");
                break;
            case 11:
                cout << "\n\nIngrese elemento: "; cin >> aux2;
                existe = (lst->buscar(aux2) != 0);
                imprimirEstado(existe);
                system("pause>null");
                break;
            case 12: 
                exit(0);
                break;
        }
    } while (opc != 12);

 
    _getch();
    return 0;
}