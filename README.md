# SparseMatrices

A set of functions to deal with sparse matrices. For first instance, the least squares method over sparse matrixes. (University team project)

## API documentation

### void QuickSort

Applies the quicksort algorithm to the vector and gives the indices modified.

**Input**
* double *vec: the vector itself
* int first, int last: indices which limits the vector that it is going to sort (it can sort a subvector)

**Output**
* double *vec: the sorted vector (by reference)
* int *indices: the indices of the sorted vector (by reference)

### double *gaussSeidel

Solves an Ax = b system where A is a sparse matrix and b a is a vector.

**Input**
* matrizSparse matriz: a matrix of type matrizSparse
* double *b: the vector b of the system

**Output**
* double x: the solution vector

### Type matrizSparse

This is how sparse matrices are stored
* int nfil: number of rows
* int ncol: number of colums
* int nza: number of non-zero values
* int *ifil: row values
* int *icol: colum values
* double *xval: values of the matrix

It is designed in such way that if A is the sparse matrix, for each i in [0, nza) we have A in ifil[i], icol[i] is xval[i]

### void matrizPorMatriz

Computes A*B, where A and B are sparse matrices

**Input**
* const matrizSparse matrizA
* const matrizSparse matrizB

** Output**
* matrizSparse *matrizAB: result of the computation matrizA*matrizB (passed by reference)

### double *matrizPorVector

Computes A*b where A is a sparse matrix and b is a vector.

**Input**
* const matrizSparse *A
* double *b

**Output**
* double *resultado: the result vector of the computation

### matrizSparse matrizTraspuesta

Trasposes a sparse matrix 

**Input**
* const matrizSparse matriz

**Output**
* matrizSparse matrizSparseT: matriz^t
