#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class Pila {
private:
    Nodo* tope;

public:
    Pila() : tope(nullptr) {}

    void push(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
    }

    void pop() {
        if (tope) {
            Nodo* temp = tope;
            tope = tope->siguiente;
            delete temp;
        } else {
            std::cout << "La pila está vacía.\n";
        }
    }

    void mostrar() {
        Nodo* temp = tope;
        std::cout << "Contenido de la pila: ";
        while (temp) {
            std::cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        std::cout << "\n";
    }
};

class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    void enqueue(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!frente) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    void dequeue() {
        if (frente) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
            if (!frente) {
                final = nullptr;
            }
        } else {
            std::cout << "La cola está vacía.\n";
        }
    }

    void mostrar() {
        Nodo* temp = frente;
        std::cout << "Contenido de la cola: ";
        while (temp) {
            std::cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        std::cout << "\n";
    }
};

int main() {
    Pila pila;
    Cola cola;

    int opcionMenuPrincipal;

    do {
        std::cout << "\n--- Menú Principal ---\n";
        std::cout << "1. Menú Pila\n";
        std::cout << "2. Menú Cola\n";
        std::cout << "3. Salir\n";
        std::cout << "Ingrese opción: ";
        std::cin >> opcionMenuPrincipal;

        switch (opcionMenuPrincipal) {
            case 1: {
                int opcionPila;
                do {
                    std::cout << "\n--- Menú Pila ---\n";
                    std::cout << "1. Añadir elemento\n";
                    std::cout << "2. Eliminar elemento\n";
                    std::cout << "3. Mostrar pila\n";
                    std::cout << "4. Salir\n";
                    std::cout << "Ingrese opción: ";
                    std::cin >> opcionPila;

                    switch (opcionPila) {
                        case 1: {
                            int elemento;
                            std::cout << "Ingrese elemento a añadir: ";
                            std::cin >> elemento;
                            pila.push(elemento);
                            break;
                        }
                        case 2:
                            pila.pop();
                            break;
                        case 3:
                            pila.mostrar();
                            break;
                        case 4:
                            std::cout << "Saliendo del menú Pila.\n";
                            break;
                        default:
                            std::cout << "Opción no válida. Intente de nuevo.\n";
                    }

                } while (opcionPila != 4);
                break;
            }

            case 2: {
                int opcionCola;
                do {
                    std::cout << "\n--- Menú Cola ---\n";
                    std::cout << "1. Añadir elemento\n";
                    std::cout << "2. Eliminar elemento\n";
                    std::cout << "3. Mostrar cola\n";
                    std::cout << "4. Salir\n";
                    std::cout << "Ingrese opción: ";
                    std::cin >> opcionCola;

                    switch (opcionCola) {
                        case 1: {
                            int elemento;
                            std::cout << "Ingrese elemento a añadir: ";
                            std::cin >> elemento;
                            cola.enqueue(elemento);
                            break;
                        }
                        case 2:
                            cola.dequeue();
                            break;
                        case 3:
                            cola.mostrar();
                            break;
                        case 4:
                            std::cout << "Saliendo del menú Cola.\n";
                            break;
                        default:
                            std::cout << "Opción no válida. Intente de nuevo.\n";
                    }

                } while (opcionCola != 4);
                break;
            }

            case 3:
                std::cout << "Saliendo del programa.\n";
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcionMenuPrincipal != 3);

    return 0;
}

//Comentario 