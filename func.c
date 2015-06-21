
#include <stdio.h>
#include <stdlib.h>

void *mimalloc( size_t tam )
{
	void *j;
	if ( (j = malloc( tam ) ) ==  NULL )
	{
		printf("No hubo memoria disponible\n");
		exit(1);
	}
	return j;
}

void *mirealloc( void *vec, size_t tam )
{
	void *j;
	if ( (j = realloc( vec, tam ) ) ==  NULL )
	{
		printf("No hubo memoria disponible\n");
		exit(1);
	}

	return j;

}

FILE *mifopen( char *nomarch, char *act )
{
	FILE *arch;
	if ( (arch = fopen( nomarch, act ) ) ==  NULL )
	{
		printf("No se pudo abrir el archivo %s\n", nomarch);
		exit(1);
	}
	return arch;
}