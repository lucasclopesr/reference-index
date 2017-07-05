#ifndef TREE_H
#define TREE_H

typedef struct Tree_str *Pointer;

typedef struct Tree_str{
	Item content;
	Pointer left, right;
} Tree;

#endif