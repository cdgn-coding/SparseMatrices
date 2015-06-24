// Carlos David G. Nexans 13-10591
// Rafael Andrés Tellez 12-11397

#ifndef MATRIZ_SPARSE
#define MATRIZ_SPARSE

#include <stdlib.h>
#include <stdio.h>

#define CASTDBL (double *)
#define TAMDBL sizeof(double)
#define MAXLEN 100


void *mimalloc( size_t tam );
void *mirealloc( void *vec, size_t tam );
FILE *mifopen( char *nomarch, char *act );

typedef struct
{
	int nfil;
	int ncol;
	int nza;
	int *ifil;
	int *icol;
	double *xval;
} matrizSparse;



#endif
