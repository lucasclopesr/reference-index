#include "../lib/Item.h"
#include "../lib/Tree.h"
#include "../lib/Library.h"

void createTree(Pointer *library){
	*library = NULL;
}

int searchFor(Item *i, Pointer p){
	if(p == NULL) return -1;

	if(i->key < p->content->key){
		searchFor(i, p->left);	
	} else if(i->key > p->content->key){
		searchFor(i, p->right);
	} else {
		*i = p->content;
	}
}

int insert(Item i, Pointer *p){
	if(*p == NULL){
		*p = (Pointer) malloc(sizeof(Tree));
		(*p)->content = i;
		(*p)->left    = NULL;
		(*p)->right   = NULL;

		return 1;
	} else if(i.key < (*p)->content.key){
		insert(i, &(*p)->left);
		return 1;
	} else if(i.key > (*p)->content.key){
		insert(i, &(*p)->right);
		return 1;
	} else {
		return 0; //Registro já existe na árvore;
	}
}

void previous(Pointer q, Pointer *r){
	if((*r)->dir != NULL){
		previous(q, &(*r)->right);
		return;
	}

	q->content = (*r)->content;
	q = *r;
	*r = (*r)->left;
	free(q);
}

void remove(Item i, Pointer *p){
	Pointer aux;

	if(*p == NULL){
		return 0; //Registro não está na árvore;
	} else if(i.key < (*p)->content.key){
		remove(i, &(*p)->left);
	} else if(i.key > (*p)->content.key){
		remove(i, &(*p)->right);
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
}
