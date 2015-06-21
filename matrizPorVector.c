
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

double *matrizPorVector(const matrizSparse *A, double *b)
{
	unsigned k; // unsigned i;
	double *resultado;
	resultado = (double *) mimalloc ( A->nfil*sizeof(double) );

	
	//Inicializamos los valores del vector resultado
	for(k=0; k<A->nfil; k++)
		*(resultado + k) = 0.0f;
	

	// De esta manera el algoritmo funciona pero tiene nfil*nza iteraciones
	// Pues se recorren todas las filas, luego todos los valores no nulos
	// for(i=0; i<nfil; i++)
	// 	for(k=0; k<nza; k++)
	// 		if( *(ifil+k) == i+1 )
	// 			*(resultado+i) += (*(b - 1 + (*(icol+k))))*(*(xval+k));



	// En lugar de esto, recorremos solo los valores no nulos
	// y los ubicamos en el resultado final

	// Cada k tal que 0<=k<nza cumple que
	// El elemento en la posicion *(ifil+k), *(icol+k) es *(xval+k)
	// Sólo hay que recordar que el conjunto de indices en los
	// vectores ifil, icol comienzan desde 1, no desde cero
	// por lo tanto debemos restarle 1 cuando utilizamos este
	// conjunto de indices

	// Como resultado obtenemos un for más compacto, y además
	// un algoritmo mucho más rapido para matrices muy grandes
	for(k=0; k < A->nza; k++)
			*(resultado+(*(A->ifil+k))-1) += (*(b - 1 + (*(A->icol+k))))*(*(A->xval+k));
	
	
	// Retornamos la direccion de memoria del comienzo del arreglo
	return resultado;
}