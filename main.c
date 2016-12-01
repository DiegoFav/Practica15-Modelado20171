#include "main.h"
// No hagas #include aquí, hazlos en main.h

int main(int argc, char const *argv[]) {
    // Verifica si hay menos de 3 parametros
    // sino entonces se imprimen las instrucciones
    // y se para la ejecución del programa
	if (argc < 3) {
		imprime_instrucciones(argv[0]);
		return 0;
	}
	//abrimos un archivo para escribir los resultados.
	FILE *out = fopen(argv[argc-1], "w");
	//imprimimos formato.
	printf("Nombre del archivo	Palabra más repetida	Número de repeticiones\n");
	fputs("Nombre del archivo	Palabra más repetida	Número de repeticiones\n", out);
	
	//operamos cada archivo.
	int i;
	for(i = 1; i < argc - 1; i++) {
		opera_archivo(argv[i], out);
	}
	
	//imprimimos formato.
	printf("Se guardó el resultado en el archivo %s\n", argv[argc-1]);
	fprintf(out, "Se guardó el resultado en el archivo %s\n", argv[argc-1]);
	//cerramos el archivo de salida.
	fclose(out);
    return 0;
}

/* ------ Aquí va la implementación de tus funciones ------ */

//opera cada archivo (solamente uno)
void opera_archivo(const char *arc, FILE *out) {
	//abrimos el archivo de entrada.
	FILE *in = fopen(arc, "r");
	char line[5000], *tokn;
	Cadena_num *tot[10000];	//arreglo de cadenas con una estancia.
	int max = 0, numcad = 0, i = 0;
	
	//leemos una linea y la ponemos en line.
	while (fgets(line, 5000, in) != NULL) {
		//tokenizamos line.
		tokn = strtok(line, " ,.-()\n\0");
		while (tokn != NULL) {
			//buscamos si la palabra ya esta en el arreglo
			for (i = 0; i < numcad; i++) {
				if(strcmp(tot[i]->cad, tokn) == 0) {
					tot[i]->n++;
					break;
				}
			}
			//si la palabra no esta en la lista entonces se agrega al arreglo.
			if (i == numcad) {
				tot[i] = (Cadena_num*) malloc(sizeof(Cadena_num));
				tot[i]->cad = (char*) malloc(strlen(tokn)+1);
				memcpy(tot[i]->cad, tokn, strlen(tokn)+1);	//copiamos la cadena en la nueva entrada
				tot[i]->n = 1;
				numcad++;
			}
			//obtenemos el siguiente token.
			tokn = strtok(NULL, " ,.-()\n\0");
		}
	}
	//buscamos el maximo de todas las distintas palabras.
	for (i = 0; i < numcad; i++) {
		if(tot[max]->n < tot[i]->n) 
			max = i;
	}
	//imprimimos formato.
	printf("%s	%s	%d\n", arc, tot[max]->cad, tot[max]->n);
	fprintf(out, "%s	%s	%d\n", arc, tot[max]->cad, tot[max]->n);
	//cerramos el archivo de entrada.
	fclose(in);
	
}

//imprime las instrucciones de uso.
void imprime_instrucciones(const char *prog) {
	printf("Uso: %s <archivo1> [<archivo2> <archivo3>..] <salida>\n", prog);
}
