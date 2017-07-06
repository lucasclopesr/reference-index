#ifndef LIBRARY_H
#define LIBRARY_H

typedef Pointer Library;

void createTree(Pointer*);
int searchFor(char*, Pointer, Item*);
int insertIntoTree(char*, Pointer*, int);
void previous(Pointer, Pointer*);
int removeFromTree(char*, Pointer*);
int compareKey(char*, char*);

#endif