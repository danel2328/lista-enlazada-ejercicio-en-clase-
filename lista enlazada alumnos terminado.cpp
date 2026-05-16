#include <iostream>
#include <string>

using namespace std;

class Alumno {
private:
    string nombres;
    string apellidos;
    string carnet;
    string email;
    string telefono;
    float notas[5];

public:

    void ingresarDatos() {

        cin.ignore(1000, '\n');

        cout << "\nIngrese nombres: ";
        getline(cin, nombres);

        cout << "Ingrese apellidos: ";
        getline(cin, apellidos);

        cout << "Ingrese carnet: ";
        getline(cin, carnet);

        cout << "Ingrese email: ";
        getline(cin, email);

        cout << "Ingrese telefono: ";
        getline(cin, telefono);

        cout << "\nIngrese las 5 notas:\n";

        for (int i = 0; i < 5; i++) {

            while (true) {

                cout << "Nota " << i + 1 << " (0 a 10): ";
                cin >> notas[i];

                // Validar letras o símbolos
                if (cin.fail()) {

                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "Entrada invalida. Ingrese un numero.\n";
                }
                // Validar rango
                else if (notas[i] < 0 || notas[i] > 10) {

                    cout << "Error: la nota debe estar entre 0 y 10.\n";
                }
                else {

                    break;
                }
            }
        }
    }

    float calcularPromedio() const {

        float suma = 0;

        for (int i = 0; i < 5; i++) {

            suma += notas[i];
        }

        return suma / 5;
    }

    void mostrarDatos() const {

        cout << "\nNombres   : " << nombres << endl;
        cout << "Apellidos : " << apellidos << endl;
        cout << "Carnet    : " << carnet << endl;
        cout << "Email     : " << email << endl;
        cout << "Telefono  : " << telefono << endl;

        cout << "Notas     : ";

        for (int i = 0; i < 5; i++) {

            cout << notas[i] << " ";
        }

        cout << "\nPromedio  : " << calcularPromedio() << endl;
    }
};

struct Nodo {

    Alumno alumno;
    Nodo* siguiente;
};

int main() {

    Nodo* inicio = NULL;
    Nodo* fin = NULL;

    char opcion;

    do {

        cout << "\nDesea agregar un alumno? (S/N): ";
        cin >> opcion;

        if (opcion == 'S' || opcion == 's') {

            Nodo* nuevoNodo = new Nodo;

            nuevoNodo->alumno.ingresarDatos();

            nuevoNodo->siguiente = NULL;

            // Insertar nodo en la lista
            if (inicio == NULL) {

                inicio = nuevoNodo;
                fin = nuevoNodo;

            } else {

                fin->siguiente = nuevoNodo;
                fin = nuevoNodo;
            }
        }

    } while (opcion == 'S' || opcion == 's');

    cout << "\n========== LISTA DE ALUMNOS ==========\n";

    Nodo* actual = inicio;

    while (actual != NULL) {

        cout << "\n--------------------------------------\n";

        actual->alumno.mostrarDatos();

        actual = actual->siguiente;
    }

    actual = inicio;

    while (actual != NULL) {

        Nodo* auxiliar = actual;

        actual = actual->siguiente;

        delete auxiliar;
    }

    cout << "\nMemoria liberada correctamente." << endl;

    return 0;
}
