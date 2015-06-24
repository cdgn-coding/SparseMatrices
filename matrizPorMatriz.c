// Carlos David G. Nexans 13-10591
// Rafael Andrés Tellez 12-11397

/*
	
	Función matrizPorMatriz : encargada de multiplicar dos matrices

	* Entrada
		De tipo matrizSparse
			matrizA
			matrizB
	* Salida
		De tipo matrizSparse
			matrizAB

	Nota: solo se pueden usar dos ciclos anidados
*/

#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"


void matrizPorMatriz( const matrizSparse matrizA, const matrizSparse matrizB, matrizSparse *matrizAB )
{
	int i, j, k, encontrado;
	// Vectores auxiliares
	int *ifil, *icol;
	double *xval;

	//No encontramos la utilidad del QuickSort para ordenar los elementos de xval ascendentemente
	//ENcontramos que sería más útil, al menos en las "Pruebas" que hicimos, ordenar los indices de fila/columna
	//Segun sea el caso, para tener una correspondencia de valores más directa, eliminando operaciones
	//Ordenar xval ascendentemente nos tomaría otro ciclo para ordenar los indices de fila/columna
	//De la matriz, para no perder la correspondencia, esto aumentaría la complejidad del algoritmo

	k=0;
	xval = (double *) mimalloc( sizeof(double) );
	ifil = (int *) mimalloc( sizeof(int) );
	icol = (int *) mimalloc( sizeof(int) );


	//Encontramos cada termino que sobrevive en las sumatorias de cada elemento de la matriz resultante
	for( i = 0; i < matrizA.nza; i++ )
	{

		for( j=0; j < matrizB.nza; j++ )
		{
			if ( *(matrizA.icol+i) == *(matrizB.ifil+j) )
			{
				if( k > 0 )
				{
					xval = (double *) mirealloc( xval, (k+1)*sizeof(double) );
					ifil = (int *) mirealloc( ifil, (k+1)*sizeof(int) );
					icol = (int *) mirealloc( icol, (k+1)*sizeof(int) );
				}

				*(xval + k) = ( *(matrizA.xval+i) )*( *(matrizB.xval+j) );
				*(ifil + k) = *(matrizA.ifil+i);
				*(icol + k) = *(matrizB.icol+j);
				k++;

			}
		}
	} //Obtiene todos los terminos que se suman en cada elemento del resultado
	//Los que coindidan en fila y columna son parte de la misma sumatoria


	matrizAB->nza = 0;
	matrizAB->xval = (double *) mimalloc( sizeof(double) );
	matrizAB->ifil = (int *) mimalloc( sizeof(int) );
	matrizAB->icol = (int *) mimalloc( sizeof(int) );

	//Buscamos coincidencia de indices de fila y columna para agrupar cada elemento en su posición
	for( i=0; i<k; i++ )
	{
		if( matrizAB->nza == 0 )
		{
			j = matrizAB->nza++;
			*(matrizAB->xval+j) = 0;
			*(matrizAB->ifil+j) = *(ifil+i);
			*(matrizAB->icol+j) = *(icol+i);
		}
		else
		{	
			encontrado = 0;

			for( j=0; j<matrizAB->nza; j++ )
				if( *(matrizAB->ifil+j) == *(ifil+i) && *(matrizAB->icol+j) == *(icol+i) )
				{
					encontrado = 1;
					break;
				}
			if ( !encontrado ) 
			{
				j = matrizAB->nza++;
				matrizAB->xval = (double *) mirealloc(matrizAB->xval, (j+1)*sizeof(double) );
				matrizAB->ifil = (int *) mirealloc(matrizAB->ifil, (j+1)*sizeof(int) );
				matrizAB->icol = (int *) mirealloc(matrizAB->icol, (j+1)*sizeof(int) );
				*(matrizAB->xval+j) = 0.0f; //Se inicializa otro espacio en cero
				*(matrizAB->ifil+j) = *(ifil+i);
				*(matrizAB->icol+j) = *(icol+i);

			}

		}
		//Siempre sumanos el valor en la posicion j del arreglo
		//El j varía, si existe otro elemento asociado a la sumatoria, entonces j es ese indice
		//De lo contrario, j es el nuevo espacio que se abrio
		*(matrizAB->xval+j) += *(xval+i);
	}

	matrizAB->nfil = matrizA.nfil;
	matrizAB->ncol = matrizB.ncol;

	
	free( ifil );
	free( icol );
	free( xval );  //Liberamos los punteros que ya no utilizaremos

}