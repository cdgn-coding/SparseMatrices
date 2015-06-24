// Carlos David G. Nexans 13-10591
// Rafael Andrés Tellez 12-11397

/*
	Programa principal : encargado de establecer conexión con el usuario

	* Pedir nombre de archivo de entrada
	* Tomar los datos del problema de cuadrados mínimos
	* Imprimir resultados en un archivo de texto resultados.txt

	Estructura del archivo resultados.txt
		cantidad de incognitas: #
		cantidad de ecuaciones: #
		solucion:
		# valor por cada línea
		.
		.
		.

	Nota: la función gaussSeidel de este programa estara en Aula Virtual
	Nota 2: probablemente stdio.h no se necesite en el main

	Nota 3: cuando se utilice exit o return en main se utilizaran las macros de stdlib.h
		EXIT_SUCCESS si el programa terminó con exito
		EXIT_FAILURE si el programa termino con un problema/error

*/

#include <stdlib.h>
#include <stdio.h>
#include "tipos.h"
#include "prototipos.h"

int main()
{
	char nombre[MAXLEN];
	int correcto, i;
	double *b, *b_sistema, *resultado;
	matrizSparse matriz, traspuesta, matriz_sistema;
	FILE *arch = mifopen("resultados.txt", "w+");

	printf("Ingrese nombre del archivo: ");
	scanf("%s", nombre);

	correcto = leeSistema(nombre, &matriz, &b);

	if ( !(correcto + 1) )
	{
		printf("El sistema no es consistente\n");
		exit(EXIT_FAILURE);
	}

	traspuesta = matrizTraspuesta(matriz);
	//Calculamos A^t


	matrizPorMatriz( traspuesta, matriz, &matriz_sistema);
	//Calculaos A^t * A

	b_sistema = matrizPorVector(&traspuesta, b);
	//Calculamos A^t * b

	resultado = gaussSeidel(matriz_sistema, b_sistema);
	//Resolvemos el sistema

	/*
		Deducimos lo siguiente del método que presenta wikipedia para este problema
	*/

	fprintf(arch, "Cantidad de incognitas: %d\n", matriz.nfil);
	fprintf(arch, "Cantidad de ecuaciones: %d\n", matriz.ncol);
	fprintf(arch, "Solucion:\n");


	for (i=0; i<matriz_sistema.nfil; i++)
	{
		fprintf(arch, "%lf\n", *(resultado+i) );
	}

	fclose(arch);

	return 0;
	

}