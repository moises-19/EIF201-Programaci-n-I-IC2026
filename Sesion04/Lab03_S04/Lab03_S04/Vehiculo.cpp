#include "Vehiculo.h"
#include <iostream>
#include <string>
namespace UNA {

    Vehiculo::Vehiculo(std::string placa, std::string marca, int anio, double kilometraje) {
        this->placa = placa;
        this->marca = marca;
        this->anio = anio;
        this->kilometraje = kilometraje;
        this->activo = true;
    }

    std::string Vehiculo::getPlaca() const {
        return placa;
    }

    std::string Vehiculo::getMarca() const {
        return marca;
    }

    int Vehiculo::getAnio() const {
        return anio;
    }

    double Vehiculo::getKilometraje() const {
        return kilometraje;
    }

    bool Vehiculo::getActivo() const {
        return activo;
    }

    void Vehiculo::registrarKilometros(double km) {

        if (activo == false) {
            std::cout << "Error: el vehiculo “ << placa << “ esta fuera de servicio, no se pueden registrar kilometros." << std::endl;
            return;
        }

        if (km <= 0) {
            std::cout << "Error: los kilometros deben ser un numero positivo." << std::endl;
            return;
        }

        kilometraje = kilometraje + km;
        std::cout << "Kilometros registrados correctamente. Nuevo kilometraje: " << kilometraje << " km" << std::endl;


    }

    void Vehiculo::desactivar() {

        if (activo == false) {
            std::cout << "El vehiculo “ << placa << “ ya esta fuera de servicio." << std::endl;
            return;
        }



        activo = false;
        std::cout << "El vehiculo " << placa << " fue puesto fuera de servicio." << std::endl;


    }


    void Vehiculo::reactivar() {

        if (activo == true) {
            std::cout << "El vehiculo “ << placa << “ ya esta activo." << std::endl;
            return;
        }
        activo = true;
        std::cout << "El vehiculo " << placa << " fue reactivado exitosamente." << std::endl;


    }

    void Vehiculo::mostrar() const {
        std::cout << "––––––––––––––" << std::endl;
        std::cout << "Placa         " << placa << std::endl;
        std::cout << "Marca         " << marca << std::endl;
        std::cout << "Año          " << anio << std::endl;
        std::cout << "Kilometraje   " << kilometraje << "km" << std::endl;

        if (activo == true) {
            std::cout << "Estado      : ACTIVO" << std::endl;
        }
        else {
            std::cout << "Estado      : FUERA DE SERVICIO" << std::endl;
        }

        std::cout << "----------------------------" << std::endl;


    }

}
