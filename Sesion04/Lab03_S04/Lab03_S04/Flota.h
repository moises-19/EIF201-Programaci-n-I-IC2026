#ifndef FLOTA_H
#define FLOTA_H

#include "Vehiculo.h"
#include <string>

namespace UNA {

	class Flota {

	private:
		Vehiculo** vehiculos;
		int cantidad;
		int capacidad;

	public:

		Flota();
		~Flota();

		void agregar(Vehiculo* nuevo);
		Vehiculo* buscarPorPlaca(std::string placa);
		void mostrarPorMarca(std::string marca);
		bool eliminar(std::string placa);
		int contarActivos();
		void mostrarTodos();


	};

}

#endif