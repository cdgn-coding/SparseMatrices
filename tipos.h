#ifndef MATRIZ_SPARSE
#define MATRIZ_SPARSE

#define CASTDBL (double *)
#define TAMDBL sizeof(double)



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
