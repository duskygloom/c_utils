#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List *createlist(void) {
    List *list = (List *)malloc(sizeof(List));
    list->length = 0;
    list->head = list->tail = NULL;
    return list;
}

void deletelist(List *list) {
    Node *curr, *next;
    for (curr = list->head; curr; curr = next) {
        next = curr->next;
        deletenode(curr);
    }
    free(list);
}

Node *createnode(type value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

void deletenode(Node *node) {
    DELETEITEM(node->value);
    free(node);
}

void printlist(const List *list, FILE *stream) {
    fputc('[', stream);
    Node *curr = list->head;
    if (!curr) {
        fputc(']', stream);
        return;
    }
    PRINTITEM(curr->value, stream);
    for (curr = curr->next; curr; curr = curr->next) {
        fputs(", ", stream);
        PRINTITEM(curr->value, stream);
    }
    fputc(']', stream);
}

Node *getnode(const List *list, int index) {
    if (index < 0) index += list->length;           // backward indexing
    if (index < 0 || index >= list->length) return NULL;
    Node *curr;
    if (index < list->length/2) {
        // forward traversal
        int step = index;       // how many times to loop
        curr = list->head;
        for (; curr && step > 0; --step)
            curr = curr->next;
    }
    else {
        // backward traversal
        curr = list->tail;
        int step = list->length - index - 1;
        for (; curr && step > 0; --step)
            curr = curr->prev;
    }
    return curr;
}

void prepend(List *list, type value) {
    Node *node = createnode(value);
    if (list->head) {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
        ++list->length;
        return;
    } 
    list->head = list->tail = node;
    ++list->length;
}

void append(List *list, type value) {
    Node *node = createnode(value);
    if (list->tail) {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
        ++list->length;
        return;
    }
    list->tail = list->head = node;
    ++list->length;
}

void insert(List *list, int index, type value) {
    if (index < 0) index += list->length + 1;           // backward indexing
    if (index < 0 || index > list->length) return;      // wrong index
    if (index == 0) {
        prepend(list, value);
        return;
    }
    else if (index == list->length) {
        append(list, value);
        return;
    }
    Node *curr;
    if (index < list->length/2) {
        // forward traversal
        int step = index;       // how many times to loop
        curr = list->head;
        for (; curr && step > 0; --step)
            curr = curr->next;
    }
    else {
        // backward traversal
        curr = list->tail;
        int step = list->length - index - 1;
        for (; curr && step > 0; --step)
            curr = curr->prev;
    }
    Node *node = createnode(value);
    node->next = curr;
    if (curr && curr->prev) curr->prev->next = node;
    else if (curr) {
        node->prev = curr->prev;
        curr->prev = node;
    }
    else list->head = node;
    ++list->length;
}

void popleft(List *list) {
    if (!list->head) return;
    Node *oldhead = list->head;
    list->head = oldhead->next;
    list->head->prev = NULL;
    --list->length;
    deletenode(oldhead);
}

void popright(List *list) {
    if (!list->tail) return;
    Node *oldtail = list->tail;
    list->tail = oldtail->prev;
    list->tail->next = NULL;
    deletenode(oldtail);
}

void pop(List *list, int index) {
    if (index < 0) index += list->length;               // backward indexing
    if (index < 0 || index > list->length) return;      // wrong index
    Node *curr;
    if (index < list->length/2) {
        // forward traversal
        int step = index;       // how many times to loop
        curr = list->head;
        for (; curr && step > 0; --step)
            curr = curr->next;
    }
    else {
        // backward traversal
        curr = list->tail;
        int step = list->length - index - 1;
        for (; curr && step > 0; --step)
            curr = curr->prev;
    }
    if (curr && curr->prev) curr->prev->next = curr->next;
    if (curr && curr->next) curr->next->prev = curr->prev;
    deletenode(curr);
    --list->length;
}
