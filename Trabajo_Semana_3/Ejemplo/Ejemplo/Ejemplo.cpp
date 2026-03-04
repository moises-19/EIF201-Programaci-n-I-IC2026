// Ejemplo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
void showTemp(int* temp) {
	std::cout << "temp desde funcion" << *temp << std::endl;
	*temp = 24;
}

int main()
{
	int temp = 35;
	int* pTemp = &temp;
	*pTemp = 36;
	temp = 40;
	std::cout << temp << std::endl;
	std::cout << *pTemp << std::endl;

	showTemp(&temp);
	std::cout << "Desde el main" << temp << std::endl;
	std::cout << *pTemp << std::endl;

	std::cout << temp;
}

