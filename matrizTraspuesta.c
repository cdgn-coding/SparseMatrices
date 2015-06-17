/*
	Funcion matrizTraspuesta : encargada de trasponer una matrizSparse

	* Entrada
		matriz
	* Salida
		matrizT

	* Se ha decidido que matriz sea un puntero de tipo matrizTraspuesta porque:
	si la matriz es muy grande no se pierde tiempo operacional en copiar los valores
	y además, las matrices se leen desde un puntero, simplemente se pasa el mismo puntero
	que ha devuelto leeSistema()

	* Se ha decidido que matrizT es un puntero de tipo matrizTraspuesta porque:
	en el ámbito en que se llame no se reservará la memoria par la matriz traspuesta
	a menos que el sistema sea válido
*/

#include <stdlib.h>

void matrizTraspuesta( matrizTraspuesta *matriz, matrizTraspuesta *matrizT )
{

}