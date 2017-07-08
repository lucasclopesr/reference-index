
/* *****************************************************
*   Autor: Lucas Caetano Lopes Rodrigues               *
*   Disciplina: AEDS 2                                 * 
*   Curso: Ciência da Computação                       *
*   Raise your words, not your voice.                  *
****************************************************** */

/*#include "Queue.c"*/
#include "Library.c"
#include <ctype.h>

const char *TREE_CONSTANT = "TREE";
const char *HASH_CONSTANT = "HASH";

void lowercase(char*, int);
void startTree(FILE*, FILE*);
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
	FILE *outputFile = fopen(outputFilePath, "w");

	if(inputFile == NULL){
		//File not found
		printf("Arquivo não encontrado.");
	} else {
		startTree(inputFile, outputFile);
	}
}

void _callHashFunction(char *inputFilePath, char *outputFilePath){
	printf("Não implementado!\n");
}

void startTree(FILE *input, FILE *outputFile){
	char word[1024], testBreakLine1, testBreakLine2;
	int size, countLines = 1;
	Library tree;
	Item i;

	createTree(&tree);

	while((testBreakLine1 = fgetc(input)) != EOF){
		if(testBreakLine1 == 10){
			if((testBreakLine2 = fgetc(input)) == 10){
				countLines++;
			}
			countLines++;
			ungetc(testBreakLine2, input);
		}
		ungetc(testBreakLine1, input);

		fscanf(input, "%1023s", word);

		size = strlen(word);
		
		if(size >= 3){
			lowercase(word, size);
			insertIntoTree(word, &tree, countLines);
		}
	}

	centralWalk(tree, outputFile);
}

void lowercase(char *word, int size){
	int i;

	for(i = 0; i < size; i++){
		word[i] = tolower(word[i]);
	}
}