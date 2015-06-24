// Carlos David G. Nexans 13-10591
// Rafael Andrés Tellez 12-11397

#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include "tipos.h"

void QuickSort( double *vec, int first, int last, int *indices );
double *gaussSeidel(matrizSparse matriz, double *b);
int leeSistema( char *nomarch, matrizSparse *matriz, double **b);
void matrizPorMatriz( const matrizSparse matrizA, const matrizSparse matrizB, matrizSparse *matrizAB );
double *matrizPorVector(const matrizSparse *A, double *b);
matrizSparse matrizTraspuesta(const matrizSparse matriz);

#endif