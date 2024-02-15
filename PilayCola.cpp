#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void menuPila(stack<int>& pila) {
    int opcion, elemento;

    do {
        cout << "\n--- Menu Pila ---\n";
        cout << "1. Añadir elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Mostrar pila\n";
        cout << "4. Salir\n";
        cout << "Ingrese Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese elemento a añadir: ";
                cin >> elemento;
                pila.push(elemento);
                break;
            case 2:
                if (!pila.empty()) {
                    cout << "Elemento eliminado: " << pila.top() << endl;
                    pila.pop();
                } else {
                    cout << "La pila está vacia.\n";
                }
                break;
            case 3:
                if (!pila.empty()) {
                    cout << "Contenido de la pila: ";
                    stack<int> temp = pila;
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                } else {
                    cout << "La pila está vacia.\n";
                }
                break;
            case 4:
                cout << "Saliendo del Menu Pila.\n";
                break;
            default:
                cout << "Opcion no válida. Intente de nuevo.\n";
        }

    } while (opcion != 4);
}

void menuCola(queue<int>& cola) {
    int opcion, elemento;

    do {
        cout << "\n--- Menu Cola ---\n";
        cout << "1. Añadir elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese elemento a añadir: ";
                cin >> elemento;
                cola.push(elemento);
                break;
            case 2:
                if (!cola.empty()) {
                    cout << "Elemento eliminado: " << cola.front() << endl;
                    cola.pop();
                } else {
                    cout << "La cola está vacia.\n";
                }
                break;
            case 3:
                if (!cola.empty()) {
                    cout << "Contenido de la cola: ";
                    queue<int> temp = cola;
                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                } else {
                    cout << "La cola está vacia.\n";
                }
                break;
            case 4:
                cout << "Saliendo del Menu Cola.\n";
                break;
            default:
                cout << "Opcion no válida. Intente de nuevo.\n";
        }

    } while (opcion != 4);
}

int main() {
    stack<int> pila;
    queue<int> cola;

    int opcionMenuPrincipal;

    do {
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Menu Pila\n";
        cout << "2. Menu Cola\n";
        cout << "3. Salir\n";
        cout << "Ingrese Opcion: ";
        cin >> opcionMenuPrincipal;

        switch (opcionMenuPrincipal) {
            case 1:
                menuPila(pila);
                break;
            case 2:
                menuCola(cola);
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no válida. Intente de nuevo.\n";
        }

    } while (opcionMenuPrincipal != 3);

    return 0;
}
