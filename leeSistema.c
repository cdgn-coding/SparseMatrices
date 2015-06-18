#include <stdio.h>
#include <stdlib.h>
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

int leeSistema( char *nomarch, matrizSparse *matriz, double *b )
{
	int valido;
	FILE *ptr;
	char c=' ';
	unsigned n=0;
	
	//Apertura del archivo
	if((ptr = fopen(nomarch,"r")) == NULL){
		printf("\n\n No se pudo abrir el archivo. Terminando programa.");
		system("pause");
		exit(1);
	}
	//Lectra del vector b
		//Designar tamaño al vector b
		if((b = (double *)malloc(sizeof(double))) == NULL){
				printf("\n\n No se pudo reservar la memoria del el vector. Terminando programa.");
				system("pause");
				exit(1);
		}
		
		//Empezar a leer e ir abriendo espacio en la memoria para b
		while(c != '\n' && c != '\r'){
			fscanf(ptr,"%lf",*(b+n));
			n++;
			//SUSTITUIR POR MIREALLOC
			if((b = (double *)realloc(b,sizeof(double)*(n+1))) == NULL){
				printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.");
				system("pause");
				exit(1);
			}
			fscanf(ptr,"%c",&c);
		}
		//Quitamos la ultima casilla de b, que fue creada pero no se le asigno ningun valor
		//SUSTITUIR POR MIREALLOC
		if((b = (double *)realloc(b,sizeof(double)*n)) == NULL){
			printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.");
			system("pause");
			exit(1);
		}
		
			
	//Lectura hasta que no haya más líneas de los elementos de ifil, icol y xval
	//Cálculo del orden de la matriz
	//Validación de datos
	return valido;
}
