#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

/*
	Funcion leeSistema : encargada de leer una matriz y un vector
	* Entrada:
		nomarch
	* Salida
		tipo entero:
			-1, si la dimension de b no coincide con el orden de la matriz
			0, si todo es consistente

	Estructura del archivo que se lee
		valores del vector b en la primera línea
		valores de ifil, icol y xval por cada línea

	Estructura de la función
		char* nomarch : entrada de la dirección de memoria de inicio de arreglo de caracteres
		matrizSparse *matriz : salida por referencia
		double **b : salida por referencia


	Se ha decidido hacer que la funcion devuelva el entero por return
	para poder usarla directamente en un if de la siguiente manera:
		if( leeSistema(...) + 1 ) { El sistema es correcto y se realizan operaciones }
		-1 + 1 = 0 == falso
		0 + 1 = 1 == verdadero
*/

int leeSistema( char *nomarch, matrizSparse *matriz, double **b)
{
	FILE *ptr;
	char c=' ';
	unsigned byte;
	unsigned n=0,tamVec,tamb;
	
	//Apertura del archivo
	if((ptr = fopen(nomarch,"r")) == NULL)
	{
		printf("\n\n No se pudo abrir el archivo. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
	//Lectra del vector b
		//Designar tamaño al vector b
	if((*b = (double *)malloc(sizeof(double))) == NULL)
	{
			printf("\n\n No se pudo reservar la memoria del el vector. Terminando programa.\n\n");
			system("pause");
			exit(1);
	}
		
		//Empezar a leer e ir abriendo espacio en la memoria para b, mientras no haya fin de linea
	while(c != '\n' && c != '\r')
	{
		fscanf(ptr,"%lf",*b+n);
		n++;
		if((*b = (double *)realloc(*b,sizeof(double)*(n+1))) == NULL){
			printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
			system("pause");
			exit(1);
		}
		fscanf(ptr,"%c",&c);
	}
	tamb = n;

	//Quitamos la ultima casilla de b, que fue creada pero no se le asigno ningun valor
	if((*b = (double *)realloc(*b,sizeof(double)*n)) == NULL){
		printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
		
	//Lectura hasta que no haya más líneas de los elementos de ifil, icol y xval
	//Dimensionamos ifil, icol y xval para un manejo mas sencillo
	if((matriz->icol = (int *)malloc(sizeof(unsigned))) == NULL){
		printf("\n\n No se pudo reservar la memoria para el vector. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
	if((matriz->ifil = (int *)malloc(sizeof(unsigned))) == NULL){
		printf("\n\n No se pudo reservar la memoria para el vector. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
	if((matriz->xval = (double *)malloc(sizeof(double))) == NULL){
		printf("\n\n No se pudo reservar la memoria para el vector. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
		
	//Hacemos el ciclo que leera y almacenara los elementos de las lineas en los vectores correspondientes
	n=0;
	while(1)
	{
		byte = fscanf(ptr,"%d %d %lf",matriz->ifil+n,matriz->icol+n,matriz->xval+n);
		n++;
		
		//Redimensionamos los 3 vectores para añadir una casilla mas
		if((matriz->icol = (int *)realloc(matriz->icol,sizeof(int)*(n+1))) == NULL){
			printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
			system("pause");
			exit(1);
		}
		if((matriz->ifil = (int *)realloc(matriz->ifil,sizeof(int)*(n+1))) == NULL){
			printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
			system("pause");
			exit(1);
		}
		if((matriz->xval = (double *)realloc(matriz->xval,sizeof(double)*(n+1))) == NULL){
			printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
			system("pause");
			exit(1);
		}
		//Rompemos el ciclo cuando llegamos al fin del archivo
		if(fscanf(ptr,"%c",&c) == EOF || byte == EOF) break;
	}

	//Guardamos el tamaño de los vectores para ser usado luego
	tamVec = n;
	//Quitamos las ultimas casillas de los 3 vectores, ya que estan sobrando
	if((matriz->icol = (int *)realloc(matriz->icol,sizeof(int)*n)) == NULL)
	{
		printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
	if((matriz->ifil = (int *)realloc(matriz->ifil,sizeof(int)*n)) == NULL)
	{
		printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
	if((matriz->xval = (double *)realloc(matriz->xval,sizeof(double)*n)) == NULL)
	{
		printf("\n\n No se pudo reservar mas memoria para el vector. Terminando programa.\n\n");
		system("pause");
		exit(1);
	}
		
	//Cálculo del orden de la matriz
	matriz->nfil = 1;  //Inicializamos en 1 para tomar //
	matriz->ncol = 1;  //El orden mayor facilmente     //
		
	//Buscamos el valor maximo en los vectores ifil e icol, que seran la ultima fila y columna de la matriz
	for(n=0;n<tamVec;n++)
	{
		if (matriz->nfil < *(matriz->ifil+n)) matriz->nfil = (*(matriz->ifil+n));
		if (matriz->ncol < *(matriz->icol+n)) matriz->ncol = (*(matriz->icol+n));
	}



	//Finalmente asignamos la cantidad de elementos no nulos (Mismos elementos del vector xval)
	//Asi que coincide con el tamaño del vector xval que definimos como tamVec
	matriz->nza = tamVec;

	//Validación de datos
		//Para resolver el sistema se debe multiplicar la transpuesta de A que denotaremos (At) por el vector b
		//Si A es de orden nxm, At sera de orden mxn, ergo la dimension de b para poder multiplicar At x b ha de ser
		//n, asi:   At(mxn) x b(nx1) = (At x A)x X. Asi que revisamos si b tiene una longitud igual al numero de 
		//filas de A.
	
	if(tamb == matriz->nfil) return(0);  //Las dimensiones SI cooncuerdan
	if(tamb != matriz->nfil) return(-1); //Las dimensiones NO cooncuerdan
	//Lo escribo asi por simplicidad de lectura, como solo hay dos casos no se escapa ninguna posibilidad.
}
