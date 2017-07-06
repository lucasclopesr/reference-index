
/* *****************************************************
*   Autor: Lucas Caetano Lopes Rodrigues               *
*   Disciplina: AEDS 2                                 * 
*   Curso: Ciência da Computação                       *
*   Where there is ruin there is hope for a treasure.  *
****************************************************** */

/*#include "Queue.c"*/
#include "Library.c"
#include <ctype.h>

const char *TREE_CONSTANT = "TREE";
const char *HASH_CONSTANT = "HASH";

void lowercase(char*, int);
void startTree(FILE*);
void _callTreeFunction(char*, char*);
void _callHashFunction(char*, char*);

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

void _callTreeFunction(char *inputFilePath, char *outputFilePath){
	FILE *inputFile = fopen(inputFilePath, "r");

	if(inputFile == NULL){
		//File not found
		printf("Arquivo não encontrado.");
	} else {
		startTree(inputFile);
	}
}

void _callHashFunction(char *inputFilePath, char *outputFilePath){
	printf("%s\n", inputFilePath);
	printf("%s\n", outputFilePath);
}

void startTree(FILE *input){
	char word[1024], breakLine;
	int size, countLines = 1;
	Library tree;
	Item i;

	createTree(&tree);

	while(fscanf(input, "%s%c", word, &breakLine) == 2){
		size = strlen(word);
		
		if(size >= 3){
			lowercase(word, size);
			insertIntoTree(word, &tree, countLines);
		}
		

		if(breakLine == '\n') countLines++;
	}
}

void lowercase(char *word, int size){
	int i;

	for(i = 0; i < size; i++){
		word[i] = tolower(word[i]);
	}
}