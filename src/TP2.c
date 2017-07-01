
/* *****************************************************
*   Autor: Lucas Caetano Lopes Rodrigues               *
*   Disciplina: AEDS 2                                 * 
*   Curso: Ciência da Computação                       *
*   Where there is ruin there is hope for a treasure.  *
****************************************************** */

#include <string.h>
#include <stdio.h>

const char *TREE_CONSTANT = "TREE";
const char *HASH_CONSTANT = "HASH";

void _callTreeFunction(char *inputFilePath, char *outputFilePath){
	printf("%s\n", inputFilePath);
	printf("%s\n", outputFilePath);
}

void _callHashFunction(char *inputFilePath, char *outputFilePath){
	printf("%s\n", inputFilePath);
	printf("%s\n", outputFilePath);
}

void main(int argc, char **argv){
	if(argc == 4){
		if(strcmp(argv[3], TREE_CONSTANT) == 0){
			_callTreeFunction(argv[1], argv[2]);
		} else if(strcmp(argv[3], HASH_CONSTANT) == 0){
			_callHashFunction(argv[1], argv[2]);
		} else {
			printf("Parametro incorreto.\n");
		}
	} else {
		printf("Numero incorreto de parametros.\n");
	}
}