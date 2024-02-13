#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class usuario {
protected:
    string nombre, contrasena;
    int edad;

public:
    usuario(string, string, int);
    void login();
    void logout();
    void change_pwd();
};

class cliente : public usuario { //clase cliente que hereda de usuario
public:
    cliente(string, string, int);
    void menuCliente();
    void comprar();
    void reclamar();
    void devolver();
};

class vendedor : public usuario { //clase vendedor que hereda de usuario
public:
    vendedor(string, string, int);
    void menuVendedor();
    void vender();
    void actualizar();
};

usuario::usuario(string _nombre, string _contrasena, int _edad) { //constructor usuario
    nombre = _nombre;
    contrasena = _contrasena;
    edad = _edad;
}

void usuario::login() {
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombre;
    cout << "Ahora ingrese su contrasena: ";
    cin >> contrasena;
}

void usuario::logout() {
    cout << "Hasta la proxima, " << nombre << endl;
    exit(EXIT_SUCCESS);
}

void usuario::change_pwd() {
    cout << "Ingrese su nueva contrasena: ";
    cin >> contrasena;
}

cliente::cliente(string _nombre, string _contrasena, int _edad) : usuario(_nombre, _contrasena, _edad) {
    // Constructor de cliente, que llama al constructor de usuario
}

void cliente::menuCliente() {
    int opcion;
    do {
        cout << "\nMenu Cliente:\n";
        cout << "1. Comprar\n";
        cout << "2. Reclamar\n";
        cout << "3. Devolver\n";
        cout << "4. Logout\n";
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                comprar();
                break;
            case 2:
                reclamar();
                break;
            case 3:
                devolver();
                break;
            case 4:
                logout();
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);
}

void cliente::comprar() {
    cout << "Cliente " << nombre << " ha realizado una compra." << endl;
}

void cliente::reclamar() {
    cout << "Cliente " << nombre << " ha presentado una reclamacion." << endl;
}

void cliente::devolver() {
    cout << "Cliente " << nombre << " ha realizado una devolucion." << endl;
}

vendedor::vendedor(string _nombre, string _contrasena, int _edad) : usuario(_nombre, _contrasena, _edad) {
    // Constructor de vendedor, que llama al constructor de usuario
}

void vendedor::menuVendedor() {
    int opcion;
    do {
        cout << "\nMenu Vendedor:\n";
        cout << "1. Vender\n";
        cout << "2. Actualizar Inventario\n";
        cout << "3. Logout\n";
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                vender();
                break;
            case 2:
                actualizar();
                break;
            case 3:
                logout();
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 3);
}

void vendedor::vender() {
    cout << "Vendedor " << nombre << " ha realizado una venta." << endl;
}

void vendedor::actualizar() {
    cout << "Vendedor " << nombre << " ha actualizado el inventario." << endl;
}

int main() {
    // Ejemplo
    cliente cliente1("Cliente1", "clave123", 25);
    vendedor vendedor1("Vendedor1", "password", 30);

    cliente1.login();
    cliente1.menuCliente();

    vendedor1.login();
    vendedor1.menuVendedor();

    return 0;
}
