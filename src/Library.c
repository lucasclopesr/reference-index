#include "../lib/qItem.h"
#include "../lib/qCell.h"
#include "../lib/Queue.h"
#include "../lib/Item.h"
#include "../lib/Tree.h"
#include "../lib/Library.h"
#include <string.h>
#include <stdio.h>

#include "../src/Queue.c"

void createTree(Pointer *library){
	*library = NULL;
}

int searchFor(char *word, Pointer p, Item *i){
	if(p == NULL) return -1;

	if(strcmp(word, p->content.word) < 0){
		searchFor(word, p->left, i);	
	} else if(strcmp(word, p->content.word) > 0){
		searchFor(word, p->right, i);
	} else {
		*i = p->content;
	}
}

void insertIntoTree(char *word, Pointer *p, int line){
	if(*p == NULL){
		*p = (Pointer) malloc(sizeof(Tree));
		(*p)->content.word = (char*) malloc(sizeof(strlen(word)));
		strcpy((*p)->content.word, word);
		(*p)->left         = NULL;
		(*p)->right        = NULL;
		createEmptyQueue(&((*p)->content.lines));
		insertInQueue(line, &((*p)->content.lines));
	} else if(strcmp(word, (*p)->content.word) < 0){
		insertIntoTree(word, &((*p)->left), line);
	} else if(strcmp(word, (*p)->content.word) > 0){
		insertIntoTree(word, &((*p)->right), line);
	} else {
		insertInQueue(line, &((*p)->content.lines)); //Registro já existe na árvore;
	}
}

void previous(Pointer q, Pointer *r){
	if((*r)->right != NULL){
		previous(q, &(*r)->right);
		return;
	}

	q->content = (*r)->content;
	q = *r;
	*r = (*r)->left;
	free(q);
}

int removeFromTree(char *word, Pointer *p){
	Pointer aux;

	if(*p == NULL){
		return 0; //Registro não está na árvore;
	} else if(strcmp(word, (*p)->content.word) < 0){
		removeFromTree(word, &(*p)->left);
	} else if(strcmp(word, (*p)->content.word) > 0){
		removeFromTree(word, &(*p)->right);
	} else if((*p)->right == NULL){
		aux = *p; 
		*p = (*p)->left;
		free(aux);
	} else if((*p)->left == NULL){
		aux = *p; 
		*p = (*p)->right;
		free(aux);
	} else {
		previous(*p, &(*p)->left);
	}
	return 1;
}

void centralWalk(Pointer p, FILE *outputFile){
	if(p == NULL) return;
	centralWalk(p->left, outputFile);
	fprintf(outputFile, "%s ", p->content.word);
	printQueue(p->content.lines, outputFile);
	fprintf(outputFile, "\n");
	centralWalk(p->right, outputFile);
}