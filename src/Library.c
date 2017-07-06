#include "../lib/qItem.h"
#include "../lib/qCell.h"
#include "../lib/Queue.h"
#include "../lib/Item.h"
#include "../lib/Tree.h"
#include "../lib/Library.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/Queue.c"

void createTree(Pointer *library){
	*library = NULL;
}

int searchFor(char *word, Pointer p, Item *i){
	if(p == NULL) return -1;

	if(compareKey(word, p->content.word) < 0){
		searchFor(word, p->left, i);	
	} else if(compareKey(word, p->content.word) > 0){
		searchFor(word, p->right, i);
	} else {
		*i = p->content;
	}
}

int insertIntoTree(char *word, Pointer *p, int line){
	if(*p == NULL){
		*p = (Pointer) malloc(sizeof(Tree));
		(*p)->content.word = word;
		(*p)->left         = NULL;
		(*p)->right        = NULL;

		return 1;
	} else if(compareKey(word, (*p)->content.word) < 0){
		insertIntoTree(word, &(*p)->left, line);
		return 1;
	} else if(compareKey(word, (*p)->content.word) > 0){
		insertIntoTree(word, &(*p)->right, line);
		return 1;
	} else {
		insertInQueue(line, &((*p)->content.lines));
		return 0; //Registro já existe na árvore;
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
	} else if(compareKey(word, (*p)->content.word) < 0){
		removeFromTree(word, &(*p)->left);
	} else if(compareKey(word, (*p)->content.word) > 0){
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

int compareKey(char *word1, char *word2){
	int size1, size2, i, j;

	size1 = strlen(word1);
	size2 = strlen(word2);

	if(size1 > size2){
		for(i = 0; i < size2; i++){
			if(word1[i] < word2[i]){
				return -1;
			} else {
				return 1;
			}
		}
		//Se não retornou: a primeira string é maior que a segunda e contém a segunda.
		return 1;
	} else if(size1 < size2){
		for(i = 0; i < size1; i++){
			if(word1[i] < word2[i]){
				return -1;
			} else {
				return 1;
			}	
		}
		//Se não retornou: a segunda string é maior que a primeira e contém a primeira.
		return -1;
	} else {
		for(i = 0; i < size1; i++){
			if(word1[i] < word2[i]){
				return -1;
			} else {
				return 1;
			}	
		}
		//Se não retornou, as duas são iguais
		return 0;
	}
}