#include "matrizSparse.h"

/*
	Funcion leeSistema : encargada de leer una matriz y un vector

	* Entrada:
		nomarch
	* Salida
		tipo entero:
			-1, si la dimension de b no coincide con el orden de la matriz
			0, si todo es consistente

		estructura matrizSparse leída del archivo
		vector dinámico b

	Estructura del archivo que se lee
		valores del vector b en la primera línea
		valores de ifil, icol y xval por cada línea

	Estructura de la función
		char* nomarch : entrada de la dirección de memoria de inicio de arreglo de caracteres
		matrizSparse *matriz : salida por referencia
		double *b : salida por referencia

	Se ha decidido hacer que la funcion devuelva el entero por return
	para poder usarla directamente en un if de la siguiente manera:
		if( leeSistema(...) + 1 ) { El sistema es correcto y se realizan operaciones }
		-1 + 1 = 0 == falso
		0 + 1 = 1 == verdadero
*/

#include <stdlib.h>
#include <stdio.h>

int leeSistema( char *nomarch, matrizSparse *matriz, double *b )
{
	int valido;
	//Apertura del archivo
	//Lectra del vector b
	//Lectura hasta que no haya más líneas de los elementos de ifil, icol y xval
	//Cálculo del orden de la matriz
	//Validación de datos
	return valido;
}