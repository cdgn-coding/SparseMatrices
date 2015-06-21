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


	k=0;
	for( i = 0; i < matrizA.nza; i++ )
	{

		for( j=0; j < matrizB.nza; j++ )
		{
			if ( *(matrizA.icol+i) == *(matrizB.ifil+j) )
			{
				if( xval == NULL )
				{
					xval = (double *) malloc( sizeof(double) );
					ifil = (int *) malloc( sizeof(int) );
					icol = (int *) malloc( sizeof(int) );
				}
				else
				{
					xval = (double *) realloc( xval, (k+1)*sizeof(double) );
					ifil = (int *) realloc( ifil, (k+1)*sizeof(int) );
					icol = (int *) realloc( icol, (k+1)*sizeof(int) );
				}

				*(xval + k) = ( *(matrizA.xval+i) )*( *(matrizA.xval+j) );
				*(ifil + k) = *(matrizA.ifil+i);
				*(icol + k) = *(matrizB.icol+j);
				k++;

			}
		}
	} //Obtiene todos los terminos que se suman en cada elemento del resultado
	//Los que coindidan en fila y columna son parte de la misma sumatoria

	matrizAB->nza = 0;
	for( i=0; i<k; i++ )
	{
		if( matrizAB->xval == NULL )
		{
			matrizAB->xval = (double *) malloc( sizeof(double) );
			matrizAB->ifil = (int *) malloc( sizeof(int) );
			matrizAB->icol = (int *) malloc( sizeof(int) );
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
				matrizAB->xval = (double *) realloc(matrizAB->xval, j*sizeof(double) );
				matrizAB->ifil = (int *) realloc(matrizAB->ifil, j*sizeof(int) );
				matrizAB->icol = (int *) realloc(matrizAB->icol, j*sizeof(int) );
				*(matrizAB->xval+j) = 0;
				*(matrizAB->ifil+j) = *(ifil+i);
				*(matrizAB->icol+j) = *(icol+i);

			}

		}

		*(matrizAB->xval+j) += *(xval+i);
	}

	matrizAB->nfil = matrizA.nfil;
	matrizAB->ncol = matrizB.ncol;

	free( ifil );
	free( icol );
	free( xval );

}