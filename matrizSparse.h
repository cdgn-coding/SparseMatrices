#ifndef MATRIZ_SPARSE
#define MATRIZ_SPARSE


typedef struct
{
	int nfil;
	int ncol;
	int nza;
	int *ifil;
	int *icol;
	double *xval;
};

#endif