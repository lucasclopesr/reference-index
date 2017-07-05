#ifndef LIBRARY_H
#define LIBRARY_H

typedef Pointer Library;

void createTree(Pointer*);
int searchFor(Item*, Pointer);
int insert(Item*, Pointer*);
void previous(Pointer, Pointer*);
void remove(Item*, Pointer*);

#endif