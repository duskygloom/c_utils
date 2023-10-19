#ifndef LIST_H
#define LIST_H

#include "../string/string.h"

// modify | to change the type of list
//        v
typedef String *type;

// define the following functions
#define DELETEITEM(item) deletestr(item)
#define PRINTITEM(item) printstr_wquotes(item)

/*
    Struct Node:
        value is a void *
        so the value must be a pointer and
            should also be casted into the
            required type
*/
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
void printlist(const List *list);
Node *getnode(const List *list, int index);

void prepend(List *list, type value);
void append(List *list, type value);
void insert(List *list, int index, type value);

void popleft(List *list);
void popright(List *list);
void pop(List *list, int index);

#endif
