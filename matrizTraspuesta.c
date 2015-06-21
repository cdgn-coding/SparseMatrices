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

#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

matrizSparse matrizTraspuesta(const matrizSparse matriz)
{
	matrizSparse matrizT;
	
	//Transponer una matriz es simplemente mover los A(i,j) a la posicion A(j,i) asi que
	//Sencillamente cambiamos ifil con icol, nfil con ncol y ya.
	
	matrizT.icol = matriz.ifil;
	matrizT.ifil = matriz.icol;
	matrizT.ncol = matriz.nfil;
	matrizT.nfil = matriz.ncol;
	
	//Luego solo completamos los otros valores que no cambian
	matrizT.nza = matriz.nza;
	matrizT.xval = matriz.xval;
	
	//Finalmente devolvemos Transpuesta y listo.
	return matrizT;
}
