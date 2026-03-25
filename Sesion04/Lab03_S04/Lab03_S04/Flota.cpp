#include "Flota.h"
#include <iostream>
#include <string>

namespace UNA {

    Flota::Flota() {
        capacidad = 3;
        cantidad = 0;
        vehiculos = new Vehiculo * [capacidad];
    }

    Flota::~Flota() {
        for (int i = 0; i < cantidad; i++) {
            delete vehiculos[i];
        }

        delete[] vehiculos;


    }

    void Flota::agregar(Vehiculo* nuevo) {

        if (cantidad == capacidad) {

            int nuevaCapacidad = capacidad * 2;

            Vehiculo** arregloNuevo = new Vehiculo * [nuevaCapacidad];


            for (int i = 0; i < cantidad; i++) {
                arregloNuevo[i] = vehiculos[i];
            }

            delete[] vehiculos;

            vehiculos = arregloNuevo;
            capacidad = nuevaCapacidad;

            std::cout << "Arreglo redimensionado. Nueva capacidad: " << capacidad << std::endl;
        }

        vehiculos[cantidad] = nuevo;
        cantidad = cantidad + 1;
        std::cout << "Vehiculo agregado correctamente." << std::endl;


    }

    Vehiculo* Flota::buscarPorPlaca(std::string placa) {

        for (int i = 0; i < cantidad; i++) {

            if (vehiculos[i]->getPlaca() == placa) {
                return vehiculos[i];
            }
        }
        return nullptr;


    }

    void Flota::mostrarPorMarca(std::string marca) {
        int contador = 0;

        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getMarca() == marca) {
                vehiculos[i]->mostrar();
                contador = contador + 1;
            }
        }

        if (contador == 0) {
            std::cout << "No se encontraron vehiculos de la marca " << marca << "." << std::endl;
        }
        else {
            std::cout << "Total de vehiculos de la marca " << marca << ": " << contador << std::endl;
        }


    }

    bool Flota::eliminar(std::string placa) {
        int posicion = -1;


        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                posicion = i;
                break;
            }
        }

        if (posicion == -1) {
            std::cout << "No se encontro ningun vehiculo con la placa " << placa << "." << std::endl;
            return false;
        }

        if (vehiculos[posicion]->getActivo() == true) {
            std::cout << "El vehiculo " << placa << " esta activo. Primero debe desactivarse antes de darlo de baja." << std::endl;
            return false;
        }

        delete vehiculos[posicion];

        for (int i = posicion; i < cantidad - 1; i++) {
            vehiculos[i] = vehiculos[i + 1];
        }

        cantidad = cantidad - 1;

        std::cout << "Vehiculo eliminado correctamente." << std::endl;
        return true;


    }

    int Flota::contarActivos() {
        int activos = 0;


        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getActivo() == true) {
                activos = activos + 1;
            }
        }

        return activos;


    }

    void Flota::mostrarTodos() {

        if (cantidad == 0) {
            std::cout << "La flota esta vacia.No hay vehiculos registrados." << std::endl;
            return;
        }


        std::cout << "=== FLOTA COMPLETA ===" << std::endl;
        std::cout << "Total de vehiculos: " << cantidad << std::endl;

        for (int i = 0; i < cantidad; i++) {
            vehiculos[i]->mostrar();
        }


    }

}