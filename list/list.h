#ifndef LIST_H
#define LIST_H

#include "../string/string.h"
#include <stdio.h>

// modify | to change the type of list
//        v
typedef float type;

// define the following functions
#define DELETEITEM(item) ;
#define PRINTITEM(item, stream) fprintf(stream, "%f", item)

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    type value;
} Node;

typedef struct List {
    int length;
    Node *head;
    Node *tail;
} List;

List *createlist(void);
void deletelist(List *list);
Node *createnode(type value);
void deletenode(Node *node);
void printpylist(const List *list, FILE *stream);
void printlist(const List *list, FILE *stream);
Node *getnode(const List *list, int index);

void prepend(List *list, type value);
void append(List *list, type value);
void insert(List *list, int index, type value);

void popleft(List *list);
void popright(List *list);
void pop(List *list, int index);

#endif
