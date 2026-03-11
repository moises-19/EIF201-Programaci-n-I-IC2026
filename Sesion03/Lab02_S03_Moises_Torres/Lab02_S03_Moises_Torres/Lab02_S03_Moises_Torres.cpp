// Lab02_S03_Moises_Torres.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include "Paquetes.h"

int main()
{
	int cantidadPaquetes = 0;

	double* pesos = crearRegistro(cantidadPaquetes);

	ingresarPesos(pesos, cantidadPaquetes);

	double total = calcularPesoTotal(pesos, cantidadPaquetes);
	double promedio = total / cantidadPaquetes;
	double limite = 0.0;
	std::cout << std::endl << "Ingrese el limite de peso permitido (kg): ";
	std::cin >> limite;

	int paquetesSobreLimite = contarSobreLimite(pesos, cantidadPaquetes, limite);
	const double* punteroMasPesado = buscarMasPesado(pesos, cantidadPaquetes);
	double valorMasPesado = *punteroMasPesado;


	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "+----------------------------------------+" << std::endl;
	std::cout << "|         RESUMEN DEL DIA                |" << std::endl;
	std::cout << "+----------------------------------------+" << std::endl;
	std::cout << "  Paquetes registrados : " << cantidadPaquetes << std::endl;
	std::cout << "  Peso total           : " << total << " kg" << std::endl;
	std::cout << "  Peso promedio        : " << promedio << " kg" << std::endl;
	std::cout << "  Limite configurado   : " << limite << " kg" << std::endl;
	std::cout << "  Sobre el limite      : " << paquetesSobreLimite << " paquete(s)" << std::endl;
	std::cout << "  Paquete mas pesado   : " << valorMasPesado << " kg" << std::endl;
	std::cout << "+----------------------------------------+" << std::endl;

	delete[] pesos;
	pesos = nullptr;

	return 0;

}