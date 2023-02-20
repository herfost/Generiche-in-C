#ifndef LIST_H_
#define LIST_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
typedef struct List List;

struct Node {
    void *data;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

//?     FUNZIONI CREAZIONE
Node    *createNode(void *data);
List    *createList(void *head_data, void *tail_data);

//?     FUNZIONI DI INSERIMENTO MEDIANTE DATO
void    insertHead(List *self, void *data);
void    insertTail(List *self, void *data);

//?     FUNZIONI DI INSERIMENTO MEDIANTE NODO
void    insertHeadNode(List *self, Node *_node);
void    insertTailNode(List *self, Node *_node);

//?     FUNZIONI DI RESTITUZIONE
void    *getData(Node *self);

Node    *getHead(List *self);
Node    *getTail(List *self);
Node    *getNodeAt(List *self, int index);
Node    *getNodeBefore(List *self, Node *_node);
Node    *getNodeAfter(Node *self);

//?     FUNZIONI DI RIMOZIONE DEI NODI 
Node    *removeHead(List *self);
Node    *removeTail(List *self);
Node    *removeNode(List *self, Node *_node);

//?     FUNZIONI DI RICERCA
Node    *findValue(List *self, void *data, int (*compare)(const void *a, const void *b));
Node    *findMin(List *self, int (*compare)(const void *a, const void *b));
Node    *findMax(List *self, int (*compare)(const void *a, const void *b));

//?     FUNZIONI DI RILASCIO DELLA MEMORIA
void    deleteData(void *self);
void    deleteNode(Node *self);
void    deleteList(List *self);

//?     FUNZIONI DI OUTPUT
void    printNode(Node *node, void printData(const void *data));
void    printList(List *self, void printData(const void *data));

#endif // LIST_H_