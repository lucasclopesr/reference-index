#ifndef QCELL_H
#define QCELL_H

typedef struct QCell_str *qPointer;

typedef struct QCell_str{
	qItem content;
	qPointer next;
} qCell;

#endif