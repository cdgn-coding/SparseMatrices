/*
	Función QuickSort : encargado de el ordenaiento de vectores
	
	Entrada:
		vec, arreglo de numeros de punto flotante
		first, last : de tipo entero, el indice menor y el indice menor en el arreglo
		indices : arreglo de enteros contiene el orden de los indices en vec

	Salida:
		los arreglos vec e indices se modificaran dentro de la función
		(solo el contenido de )
*/

void QuickSort( double *vec, int first, int last, int *indices )
{
	// Algoritmo descrito en el Anexo
	int i = first, j = last, pivote = ( *(vec+first) + *(vec+last) )/2;
	while ( i<j )
	{
		while( *(vec + i) < pivote ) i++;
		while( *(vec + j) > pivote ) j--;

		if ( i<=j )
		{
			// Intercambiamos vec[i] con vec[j]
			*(vec+i) = (-1)*(*(vec+i)) + *(vec+j) + ( *(vec+j) = *(vec+i) );
			//Intercambiamos indices[i] con indices[j]
			*(indices+i) = (-1)*(*(indices+i)) + *(indices+j) + ( *(indices+j) = *(indices+i) );
			i++;
			j--;

		}
	}

	if ( first < j ) QuickSort( vec, first, j, indices );

	if ( last > i ) QuickSort( vec, i, last, indices );

}