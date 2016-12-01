#ifndef MAIN_H // Guarda para evitar include circulares
#define MAIN_H
/* ------ Se hacen todos los includes necesarios ------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------ Definición de tus estructuras ------ */
//estructura para hacer una asociacion cadena-numero de instancias.
typedef struct {
	char *cad;	//cadena 
	int n;		//numero de instancias en algun archivo.
}Cadena_num;

/* ------ Definición de tus funciones ------ */

/*Imprime las instrucciones de uso del programa*/
void imprime_instrucciones(const char*);

//opera un solo archivo.
void opera_archivo(const char*, FILE*);

#endif //MAIN_H
