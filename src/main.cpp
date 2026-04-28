/*
 ============================================================
   ARBOL BINARIO DE BUSQUEDA - ORGANIGRAMA EMPRESARIAL
   Asignatura : Estructura de Datos
   Lenguaje   : C++
   Compilador : Dev-C++ / g++
 ============================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ---------------------------------------------------------
//  ESTRUCTURAS
// ---------------------------------------------------------

struct Empleado {
    int    codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo*    izquierdo;
    Nodo*    derecho;

    Nodo(Empleado emp) {
        dato       = emp;
        izquierdo  = nullptr;
        derecho    = nullptr;
    }
};

// ---------------------------------------------------------
//  CLASE BST
// ---------------------------------------------------------

class ArbolBST {
private:
    Nodo* raiz;

    // -- INSERTAR ------------------------------------------
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr)
            return new Nodo(emp);

        if (emp.codigo < nodo->dato.codigo)
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        else if (emp.codigo > nodo->dato.codigo)
            nodo->derecho   = insertar(nodo->derecho,   emp);
        else
            cout << "\n  [!] El codigo " << emp.codigo << " ya existe en el arbol.\n";

        return nodo;
    }

    // -- BUSCAR --------------------------------------------
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo)
            return nodo;
        if (codigo < nodo->dato.codigo)
            return buscar(nodo->izquierdo, codigo);
        else
            return buscar(nodo->derecho,   codigo);
    }

    // -- RECORRIDOS ----------------------------------------
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            imprimirFila(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            imprimirFila(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            imprimirFila(nodo);
        }
    }

    // -- ALTURA --------------------------------------------
    int altura(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int izq = altura(nodo->izquierdo);
        int der = altura(nodo->derecho);
        return 1 + max(izq, der);
    }

    // -- HOJAS ---------------------------------------------
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr)
                imprimirFila(nodo);
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    // -- CONTAR NODOS --------------------------------------
    int contarNodos(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + contarNodos(nodo->izquierdo) + contarNodos(nodo->derecho);
    }

    // -- ELIMINAR ------------------------------------------
    Nodo* encontrarMinimo(Nodo* nodo) {
        while (nodo->izquierdo != nullptr)
            nodo = nodo->izquierdo;
        return nodo;
    }

    Nodo* eliminar(Nodo* nodo, int codigo) {
        if (nodo == nullptr) {
            cout << "\n  [!] Empleado con codigo " << codigo << " no encontrado.\n";
            return nodo;
        }
        if (codigo < nodo->dato.codigo)
            nodo->izquierdo = eliminar(nodo->izquierdo, codigo);
        else if (codigo > nodo->dato.codigo)
            nodo->derecho   = eliminar(nodo->derecho,   codigo);
        else {
            // Nodo con un solo hijo o sin hijos
            if (nodo->izquierdo == nullptr) {
                Nodo* temp = nodo->derecho;
                delete nodo;
                return temp;
            } else if (nodo->derecho == nullptr) {
                Nodo* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }
            // Nodo con dos hijos: sucesor inorden
            Nodo* sucesor   = encontrarMinimo(nodo->derecho);
            nodo->dato      = sucesor->dato;
            nodo->derecho   = eliminar(nodo->derecho, sucesor->dato.codigo);
        }
        return nodo;
    }

    // -- IMPRIMIR FILA FORMATEADA --------------------------
    void imprimirFila(Nodo* nodo) {
        cout << "  | "
             << setw(6) << left  << nodo->dato.codigo
             << " | "
             << setw(25) << left << nodo->dato.nombre
             << " | "
             << setw(22) << left << nodo->dato.cargo
             << " |" << endl;
    }

    // -- ENCABEZADO DE TABLA -------------------------------
    void encabezadoTabla() {
        cout << "\n  +" << string(8,'-') << "+" << string(27,'-')
             << "+" << string(24,'-') << "+" << endl;
        cout << "  | "
             << setw(6)  << left << "Codigo"
             << " | "
             << setw(25) << left << "Nombre"
             << " | "
             << setw(22) << left << "Cargo"
             << " |" << endl;
        cout << "  +" << string(8,'-') << "+" << string(27,'-')
             << "+" << string(24,'-') << "+" << endl;
    }

    void pieTabla() {
        cout << "  +" << string(8,'-') << "+" << string(27,'-')
             << "+" << string(24,'-') << "+" << endl;
    }

public:
    ArbolBST() { raiz = nullptr; }

    // -- PUBLICAS ------------------------------------------

    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
        cout << "\n  [OK] Empleado insertado correctamente.\n";
    }

    void eliminarEmpleado(int codigo) {
        raiz = eliminar(raiz, codigo);
    }

    void buscarEmpleado(int codigo) {
        Nodo* res = buscar(raiz, codigo);
        if (res != nullptr) {
            cout << "\n  [OK] Empleado encontrado:";
            encabezadoTabla();
            imprimirFila(res);
            pieTabla();
        } else {
            cout << "\n  [!] Empleado con codigo " << codigo << " no encontrado.\n";
        }
    }

    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\n  Raiz del arbol:";
            encabezadoTabla();
            imprimirFila(raiz);
            pieTabla();
        } else {
            cout << "\n  [!] El arbol esta vacio.\n";
        }
    }

    void mostrarInorden() {
        cout << "\n  Recorrido INORDEN (orden ascendente por codigo):";
        encabezadoTabla();
        inorden(raiz);
        pieTabla();
    }

    void mostrarPreorden() {
        cout << "\n  Recorrido PREORDEN (raiz, izquierda, derecha):";
        encabezadoTabla();
        preorden(raiz);
        pieTabla();
    }

    void mostrarPostorden() {
        cout << "\n  Recorrido POSTORDEN (izquierda, derecha, raiz):";
        encabezadoTabla();
        postorden(raiz);
        pieTabla();
    }

    void mostrarAltura() {
        cout << "\n  Altura del arbol: " << altura(raiz) << " nivel(es)\n";
    }

    void mostrarNodosHoja() {
        cout << "\n  Nodos HOJA (sin hijos):";
        encabezadoTabla();
        mostrarHojas(raiz);
        pieTabla();
    }

    void mostrarTotalNodos() {
        cout << "\n  Total de empleados registrados: " << contarNodos(raiz) << "\n";
    }

    bool estaVacio() {
        return raiz == nullptr;
    }
};

// ---------------------------------------------------------
//  UTILIDADES DE INTERFAZ
// ---------------------------------------------------------

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    cout << "\n  Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void cabecera() {
    cout << "\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  |      ARBOL BST  -  ORGANIGRAMA EMPRESARIAL       |\n";
    cout << "  |          Estructura de Datos  |  C++             |\n";
    cout << "  +--------------------------------------------------+\n";
}

void menu() {
    cout << "\n";
    cout << "  +---------------------------------+\n";
    cout << "  |           MENU PRINCIPAL        |\n";
    cout << "  +---------------------------------+\n";
    cout << "  |  1. Insertar empleado           |\n";
    cout << "  |  2. Buscar empleado             |\n";
    cout << "  |  3. Eliminar empleado           |\n";
    cout << "  |  4. Mostrar raiz                |\n";
    cout << "  |  5. Recorrido inorden           |\n";
    cout << "  |  6. Recorrido preorden          |\n";
    cout << "  |  7. Recorrido postorden         |\n";
    cout << "  |  8. Altura del arbol            |\n";
    cout << "  |  9. Nodos hoja                  |\n";
    cout << "  | 10. Total de empleados          |\n";
    cout << "  |  0. Salir                       |\n";
    cout << "  +---------------------------------+\n";
    cout << "  Seleccione una opcion: ";
}

// ---------------------------------------------------------
//  MAIN
// ---------------------------------------------------------

int main() {
    ArbolBST arbol;
    int opcion;

    // -- Cargar datos de prueba automÃ¡ticamente ------------
    Empleado prueba[] = {
        {50, "Empresa UTA",       "Raiz / Empresa"     },
        {30, "Gerente de Ventas", "Nodo Interno"       },
        {70, "Gerente Finanzas",  "Nodo Interno"       },
        {20, "Empleado 1",        "Hoja - Ventas"      },
        {40, "Empleado 2",        "Hoja - Ventas"      },
        {60, "Empleado 3",        "Hoja - Finanzas"    },
        {80, "Empleado 4",        "Hoja - Finanzas"    }
    };

    for (int i = 0; i < 7; i++)
        arbol.insertarEmpleado(prueba[i]);

    do {
        limpiarPantalla();
        cabecera();
        menu();
        cin >> opcion;

        switch (opcion) {

            case 1: {
                Empleado emp;
                cout << "\n  -- INSERTAR EMPLEADO --\n";
                cout << "  Codigo : "; cin >> emp.codigo;
                cin.ignore();
                cout << "  Nombre : "; getline(cin, emp.nombre);
                cout << "  Cargo  : "; getline(cin, emp.cargo);
                arbol.insertarEmpleado(emp);
                pausar();
                break;
            }

            case 2: {
                int cod;
                cout << "\n  -- BUSCAR EMPLEADO --\n";
                cout << "  Codigo a buscar: "; cin >> cod;
                arbol.buscarEmpleado(cod);
                pausar();
                break;
            }

            case 3: {
                int cod;
                cout << "\n  -- ELIMINAR EMPLEADO --\n";
                cout << "  Codigo a eliminar: "; cin >> cod;
                arbol.eliminarEmpleado(cod);
                cout << "\n  [OK] Operacion realizada.\n";
                pausar();
                break;
            }

            case 4:
                arbol.mostrarRaiz();
                pausar();
                break;

            case 5:
                arbol.mostrarInorden();
                pausar();
                break;

            case 6:
                arbol.mostrarPreorden();
                pausar();
                break;

            case 7:
                arbol.mostrarPostorden();
                pausar();
                break;

            case 8:
                arbol.mostrarAltura();
                pausar();
                break;

            case 9:
                arbol.mostrarNodosHoja();
                pausar();
                break;

            case 10:
                arbol.mostrarTotalNodos();
                pausar();
                break;

            case 0:
                cout << "\n  Hasta luego\n\n";
                break;

            default:
                cout << "\n  [!] Opcion invalida. Intente de nuevo.\n";
                pausar();
        }

    } while (opcion != 0);

    return 0;
}