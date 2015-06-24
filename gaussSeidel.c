#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tipos.h"

#define MAXITER 1000
#define TOL 1.e-8

double *gaussSeidel(matrizSparse matriz, double *b)
{
	//Aqui faltaba inicializar k
	unsigned i, j, k=0, tam = matriz.nfil, nza = matriz.nza;
	double *x, *y, *diag, *res, suma, maxi;
	
	x = CASTDBL mimalloc(tam*TAMDBL);
	y = CASTDBL mimalloc(tam*TAMDBL);
	diag = CASTDBL mimalloc(tam*TAMDBL);
	res = CASTDBL mimalloc(tam*TAMDBL);
	
	// Se define el iterado inicial como un vector de ceros
	for (i = 0; i < tam; i++)
		*(x + i) = 0.0;
	
	// Almaceno la diagonal de la matriz en el arreglo diag
	j = 0;
	for (i = 0; i < nza; i++)
		if (*(matriz.ifil + i) == *(matriz.icol + i))
			*(diag + k++) = *(matriz.xval + i);
	
	// Comienza el ciclo de iteraciones
	for (k = 1; k <= MAXITER; k++) {
		// Se almacena la iteración anterior en el arreglo y
		for (i = 0; i < tam; i++)
			*(y + i) = *(x + i);
		// Ciclo de Gauss Seidel
		for (i = 0; i < tam; i++) {
			suma = 0.0;
			for (j = 0; j < nza; j++) {
				// Si el elemento no es el de la digonal, se realiza el cálculo
				if ( (*(matriz.ifil + j) == i+1) && (*(matriz.icol + j) != i+1) )
					suma += *(matriz.xval + j)*(*(x + *(matriz.icol + j)-1));	
			}
			*(x + i) = (*(b + i) - suma)/(*(diag + i));
		}
		
		// Definimos el vector que contiene la resta de los iterados
		for (i = 0; i < tam; i++)
			*(res + i) = fabs(*(y + i) - *(x + i));
		
		// Calculamos el máximo del vector
		maxi = *res;
		for (i = 1; i < tam; i++)
			if (*(res + i) > maxi) maxi = *(res + i);
		
		// Si el máximo del vector es menor que la tolerancia, hay convergencia
		if (maxi < TOL) return x;
	}
	
	
	printf("\n\n------Gauss Seidel no convergio------\n\n");
	
	return x;
}
