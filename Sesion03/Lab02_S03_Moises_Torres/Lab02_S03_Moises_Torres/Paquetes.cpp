#include "Paquetes.h"
#include <iostream>

double* crearRegistro(int& cantidad)
{
    std::cout << "+-----------------------------+" << std::endl;
    std::cout << "| Sistema de Control de Pesos |" << std::endl;
    std::cout << "+-----------------------------+" << std::endl;
    std::cout << "Ingrese la cantidad de paquetes del dia: ";
    std::cin >> cantidad;

    while (cantidad <= 0)
    {
        std::cout << "Error: debe ser mayor a cero ";
        std::cin >> cantidad;
    }
    double* pesos = new double[cantidad];

    return pesos;
}

void ingresarPesos(double* pesos, int cantidad)
{
    std::cout << std::endl << "Ingrese el peso de cada paquete en kg:" << std::endl;

    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "  Paquete " << (i + 1) << ": ";
        std::cin >> pesos[i];

        while (pesos[i] <= 0)
        {
            std::cout << "  Error: el peso debe ser mayor a cero. Ingrese de nuevo: ";
            std::cin >> pesos[i];
        }
    }

}

double calcularPesoTotal(const double* pesos, int cantidad)
{
    double suma = 0.0;

    for (int i = 0; i < cantidad; i++)
    {
        suma += pesos[i];
    }

    return suma;


}

int contarSobreLimite(const double* pesos, int cantidad, double limite)
{
    int contador = 0;


    for (int i = 0; i < cantidad; i++)
    {
        if (pesos[i] > limite)
        {
            contador++;
        }
    }

    return contador;


}

const double* buscarMasPesado(const double* pesos, int cantidad)
{
    int posicionMayor = 0;


    for (int i = 1; i < cantidad; i++)
    {
        if (pesos[i] > pesos[posicionMayor])
        {
            posicionMayor = i;
        }
    }

    return &pesos[posicionMayor];
}

 