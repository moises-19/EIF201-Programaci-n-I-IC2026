#include <iostream>
#include <string>
#include "Flota.h"
#include "Vehiculo.h"

using namespace UNA;

int main() {


    Flota miFlota;

    int opcion = 0;

    while (opcion != 10) {


        std::cout << std::endl;
        std::cout << "===== FLOTAEXPRESS - MENU PRINCIPAL =====" << std::endl;
        std::cout << "1.  Registrar vehiculo" << std::endl;
        std::cout << "2.  Buscar vehiculo por placa" << std::endl;
        std::cout << "3.  Mostrar vehiculos por marca" << std::endl;
        std::cout << "4.  Registrar kilometros a un vehiculo" << std::endl;
        std::cout << "5.  Desactivar vehiculo (fuera de servicio)" << std::endl;
        std::cout << "6.  Reactivar vehiculo" << std::endl;
        std::cout << "7.  Eliminar vehiculo (dar de baja definitiva)" << std::endl;
        std::cout << "8.  Mostrar flota completa" << std::endl;
        std::cout << "9.  Mostrar cantidad de vehiculos activos" << std::endl;
        std::cout << "10. Salir" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;


        if (opcion == 1) {

            std::string placa, marca;
            int anio;
            double km;

            std::cout << "=== REGISTRAR VEHICULO ===" << std::endl;
            std::cout << "Ingrese la placa (ej: SJO-1234): ";
            std::cin >> placa;

            std::cout << "Ingrese la marca: ";
            std::cin >> marca;

            std::cout << "Ingrese el anio de fabricacion: ";
            std::cin >> anio;

            std::cout << "Ingrese el kilometraje actual: ";
            std::cin >> km;

            Vehiculo* v = new Vehiculo(placa, marca, anio, km);
            miFlota.agregar(v);

        }
        else if (opcion == 2) {
            std::string placa;

            std::cout << "=== BUSCAR VEHICULO ===" << std::endl;
            std::cout << "Ingrese la placa a buscar: ";
            std::cin >> placa;

            Vehiculo* resultado = miFlota.buscarPorPlaca(placa);

            if (resultado == nullptr) {
                std::cout << "No se encontro ningun vehiculo con la placa " << placa << "." << std::endl;
            }
            else {
                std::cout << "Vehiculo encontrado:" << std::endl;
                resultado->mostrar();
            }

        }
        else if (opcion == 3) {
            std::string marca;

            std::cout << "=== VEHICULOS POR MARCA ===" << std::endl;
            std::cout << "Ingrese la marca a buscar: ";
            std::cin >> marca;

            miFlota.mostrarPorMarca(marca);

        }
        else if (opcion == 4) {
            std::string placa;
            double km;

            std::cout << "=== REGISTRAR KILOMETROS ===" << std::endl;
            std::cout << "Ingrese la placa del vehiculo: ";
            std::cin >> placa;

            Vehiculo* v = miFlota.buscarPorPlaca(placa);

            if (v == nullptr) {
                std::cout << "No se encontro el vehiculo con placa " << placa << "." << std::endl;
            }
            else {
                std::cout << "Ingrese los kilometros a registrar: ";
                std::cin >> km;
                v->registrarKilometros(km);
            }

        }
        else if (opcion == 5) {
            std::string placa;

            std::cout << "=== DESACTIVAR VEHICULO ===" << std::endl;
            std::cout << "Ingrese la placa del vehiculo: ";
            std::cin >> placa;

            Vehiculo* v = miFlota.buscarPorPlaca(placa);

            if (v == nullptr) {
                std::cout << "No se encontro el vehiculo con placa " << placa << "." << std::endl;
            }
            else {
                v->desactivar();
            }

        }
        else if (opcion == 6) {
            std::string placa;

            std::cout << "=== REACTIVAR VEHICULO ===" << std::endl;
            std::cout << "Ingrese la placa del vehiculo: ";
            std::cin >> placa;

            Vehiculo* v = miFlota.buscarPorPlaca(placa);

            if (v == nullptr) {
                std::cout << "No se encontro el vehiculo con placa " << placa << "." << std::endl;
            }
            else {
                v->reactivar();
            }

        }
        else if (opcion == 7) {
            std::string placa;

            std::cout << "=== ELIMINAR VEHICULO ===" << std::endl;
            std::cout << "Ingrese la placa del vehiculo a eliminar: ";
            std::cin >> placa;

            miFlota.eliminar(placa);

        }
        else if (opcion == 8) {
            miFlota.mostrarTodos();

        }
        else if (opcion == 9) {
            int activos = miFlota.contarActivos();
            std::cout << "Cantidad de vehiculos activos: " << activos << std::endl;

        }
        else if (opcion == 10) {
            std::cout << "Hasta luego!" << std::endl;

        }
        else {
            std::cout << "Opcion no valida. Por favor ingrese un numero del 1 al 10." << std::endl;
        }
    }

    return 0;


}