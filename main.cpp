#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Definir los arrays paralelos
int facturas[200];
int cedulas[200];
string nombres[200];
int localidades[200];
int cantidadesEntradas[200];
double subtotales[200];
double cargosServiciosArray[200];
double totalesPagar[200];

int cantidadVentas = 0; // Llevar la cuenta del número de ventas registradas
int cantidadSol = 0, cantidadSombra = 0, cantidadPreferencial = 0;
double acumuladoSol = 0, acumuladoSombra = 0, acumuladoPreferencial = 0;

void agregarVenta();
void consultarVenta(int factura);
void modificarVenta(int factura);
void borrarVenta(int factura);
void mostrarEstadisticas();
int buscarVenta(int factura);

int main() {
    char opcion;

    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar Venta\n";
        cout << "2. Consultar Venta\n";
        cout << "3. Modificar Venta\n";
        cout << "4. Borrar Venta\n";
        cout << "5. Mostrar Estadisticas\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                agregarVenta();
                break;
            case '2': {
                int factura;
                cout << "Ingrese el numero de factura a consultar: ";
                cin >> factura;
                consultarVenta(factura);
                break;
            }
            case '3': {
                int factura;
                cout << "Ingrese el numero de factura a modificar: ";
                cin >> factura;
                modificarVenta(factura);
                break;
            }
            case '4': {
                int factura;
                cout << "Ingrese el numero de factura a borrar: ";
                cin >> factura;
                borrarVenta(factura);
                break;
            }
            case '5':
                mostrarEstadisticas();
                break;
            case '6':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != '6');

    return 0;
}

void agregarVenta() {
    if (cantidadVentas >= 200) {
        cout << "Error: Se ha alcanzado el numero maximo de ventas." << endl;
        return;
    }

    int factura, cedula, localidad, cantidadEntradas;
    string nombre;
    double subtotalTemp, cargosServiciosTemp, totalPagarTemp;

    cout << "Ingrese el numero de factura: ";
    cin >> factura;
    cout << "Ingrese la cedula del comprador: ";
    cin >> cedula;
    cout << "Ingrese el nombre del comprador: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la localidad (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ";
    cin >> localidad;
    cout << "Ingrese la cantidad de entradas (máximo 4): ";
    cin >> cantidadEntradas;

    if (cantidadEntradas > 4) {
        cout << "Error: La cantidad de entradas no puede exceder 4." << endl;
        return;
    }

    switch (localidad) {
        case 1:
            subtotalTemp = cantidadEntradas * 10500;
            cargosServiciosTemp = cantidadEntradas * 1000;
            totalPagarTemp = subtotalTemp + cargosServiciosTemp;
            cantidadSol += cantidadEntradas;
            acumuladoSol += subtotalTemp;
            break;
        case 2:
            subtotalTemp = cantidadEntradas * 20500;
            cargosServiciosTemp = cantidadEntradas * 1000;
            totalPagarTemp = subtotalTemp + cargosServiciosTemp;
            cantidadSombra += cantidadEntradas;
            acumuladoSombra += subtotalTemp;
            break;
        case 3:
            subtotalTemp = cantidadEntradas * 25500;
            cargosServiciosTemp = cantidadEntradas * 1000;
            totalPagarTemp = subtotalTemp + cargosServiciosTemp;
            cantidadPreferencial += cantidadEntradas;
            acumuladoPreferencial += subtotalTemp;
            break;
        default:
            cout << "Error: Localidad invalida." << endl;
            return;
    }

    // Guardar los valores en los arrays
    facturas[cantidadVentas] = factura;
    cedulas[cantidadVentas] = cedula;
    nombres[cantidadVentas] = nombre;
    localidades[cantidadVentas] = localidad;
    cantidadesEntradas[cantidadVentas] = cantidadEntradas;
    subtotales[cantidadVentas] = subtotalTemp;
    cargosServiciosArray[cantidadVentas] = cargosServiciosTemp;
    totalesPagar[cantidadVentas] = totalPagarTemp;

    cantidadVentas++;

    cout << fixed << setprecision(2);
    cout << "\nDatos de la venta:\n";
    cout << "Numero de Factura: " << factura << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Nombre Comprador: " << nombre << endl;
    cout << "Localidad: ";
    switch (localidad) {
        case 1:
            cout << "Sol Norte/Sur" << endl;
            break;
        case 2:
            cout << "Sombra Este/Oeste" << endl;
            break;
        case 3:
            cout << "Preferencial" << endl;
            break;
    }
    cout << "Cantidad de Entradas: " << cantidadEntradas << endl;
    cout << "Subtotal: " << subtotalTemp << endl;
    cout << "Cargos por Servicios: " << cargosServiciosTemp << endl;
    cout << "Total a Pagar: " << totalPagarTemp << endl;
}

void consultarVenta(int factura) {
    int indice = buscarVenta(factura);
    if (indice == -1) {
        cout << "Venta no encontrada." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\nDatos de la venta:\n";
    cout << "Numero de Factura: " << facturas[indice] << endl;
    cout << "Cedula: " << cedulas[indice] << endl;
    cout << "Nombre Comprador: " << nombres[indice] << endl;
    cout << "Localidad: ";
    switch (localidades[indice]) {
        case 1:
            cout << "Sol Norte/Sur" << endl;
            break;
        case 2:
            cout << "Sombra Este/Oeste" << endl;
            break;
        case 3:
            cout << "Preferencial" << endl;
            break;
    }
    cout << "Cantidad de Entradas: " << cantidadesEntradas[indice] << endl;
    cout << "Subtotal: " << subtotales[indice] << endl;
    cout << "Cargos por Servicios: " << cargosServiciosArray[indice] << endl;
    cout << "Total a Pagar: " << totalesPagar[indice] << endl;
}

void modificarVenta(int factura) {
    int indice = buscarVenta(factura);
    if (indice == -1) {
        cout << "Venta no encontrada." << endl;
        return;
    }

    int cedula, localidad, cantidadEntradas;
    string nombre;
    double subtotalTemp, cargosServiciosTemp, totalPagarTemp;

    cout << "Ingrese la nueva cedula del comprador: ";
    cin >> cedula;
    cout << "Ingrese el nuevo nombre del comprador: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la nueva localidad (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ";
    cin >> localidad;
    cout << "Ingrese la nueva cantidad de entradas (máximo 4): ";
    cin >> cantidadEntradas;

    if (cantidadEntradas > 4) {
        cout << "Error: La cantidad de entradas no puede exceder 4." << endl;
        return;
    }

    // Restar las entradas y subtotales anteriores
    switch (localidades[indice]) {
        case 1:
            cantidadSol -= cantidadesEntradas[indice];
            acumuladoSol -= subtotales[indice];
            break;
        case 2:
            cantidadSombra -= cantidadesEntradas[indice];
            acumuladoSombra -= subtotales[indice];
            break;
        case 3:
            cantidadPreferencial -= cantidadesEntradas[indice];
            acumuladoPreferencial -= subtotales[indice];
            break;
    }

    // Calcular los nuevos valores
    switch (localidad) {
        case 1:
            subtotalTemp = cantidadEntradas * 10500;
            cargosServiciosTemp = cantidadEntradas * 1000;
            totalPagarTemp = subtotalTemp + cargosServiciosTemp;
            cantidadSol += cantidadEntradas;
            acumuladoSol += subtotalTemp;
            break;
        case 2:
            subtotalTemp = cantidadEntradas * 20500;
            cargosServiciosTemp = cantidadEntradas * 1000;
            totalPagarTemp = subtotalTemp + cargosServiciosTemp;
            cantidadSombra += cantidadEntradas;
            acumuladoSombra += subtotalTemp;
            break;
        case 3:
            subtotalTemp = cantidadEntradas * 25500;
            cargosServiciosTemp = cantidadEntradas * 1000;
            totalPagarTemp = subtotalTemp + cargosServiciosTemp;
            cantidadPreferencial += cantidadEntradas;
            acumuladoPreferencial += subtotalTemp;
            break;
        default:
            cout << "Error: Localidad invalida." << endl;
            return;
    }

    // Guardar los nuevos valores en los arrays
    cedulas[indice] = cedula;
    nombres[indice] = nombre;
    localidades[indice] = localidad;
    cantidadesEntradas[indice] = cantidadEntradas;
    subtotales[indice] = subtotalTemp;
    cargosServiciosArray[indice] = cargosServiciosTemp;
    totalesPagar[indice] = totalPagarTemp;

    cout << "Venta modificada exitosamente." << endl;
}

void borrarVenta(int factura) {
    int indice = buscarVenta(factura);
    if (indice == -1) {
        cout << "Venta no encontrada." << endl;
        return;
    }

    // Restar las entradas y subtotales anteriores
    switch (localidades[indice]) {
        case 1:
            cantidadSol -= cantidadesEntradas[indice];
            acumuladoSol -= subtotales[indice];
            break;
        case 2:
            cantidadSombra -= cantidadesEntradas[indice];
            acumuladoSombra -= subtotales[indice];
            break;
        case 3:
            cantidadPreferencial -= cantidadesEntradas[indice];
            acumuladoPreferencial -= subtotales[indice];
            break;
    }

    // Mover los elementos hacia la izquierda para sobrescribir la venta borrada
    for (int i = indice; i < cantidadVentas - 1; i++) {
        facturas[i] = facturas[i + 1];
        cedulas[i] = cedulas[i + 1];
        nombres[i] = nombres[i + 1];
        localidades[i] = localidades[i + 1];
        cantidadesEntradas[i] = cantidadesEntradas[i + 1];
        subtotales[i] = subtotales[i + 1];
        cargosServiciosArray[i] = cargosServiciosArray[i + 1];
        totalesPagar[i] = totalesPagar[i + 1];
    }

    cantidadVentas--;

    cout << "Venta borrada exitosamente." << endl;
}

void mostrarEstadisticas() {
    cout << fixed << setprecision(2);
    cout << "\nEstadisticas:\n";
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << cantidadSol << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << acumuladoSol << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << cantidadSombra << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << acumuladoSombra << endl;
    cout << "Cantidad Entradas Localidad Preferencial: " << cantidadPreferencial << endl;
    cout << "Acumulado Dinero Localidad Preferencial: " << acumuladoPreferencial << endl;
}

int buscarVenta(int factura) {
    for (int i = 0; i < cantidadVentas; i++) {
        if (facturas[i] == factura) {
            return i;
        }
    }
    return -1;
}


