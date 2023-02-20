#include "list.h"

//?     FUNZIONI CREAZIONE
Node    *createNode(void *data)
{
    Node *_node = malloc(sizeof *_node);
    if (_node == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di un Nodo\n");
        return NULL;
    }

    _node->data = data;
    _node->next = NULL;

    return _node;
}

List    *createList(void *head_data, void *tail_data)
{
    List *_list = malloc(sizeof *_list);
    if (_list == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di una Lista\n");
        return NULL;
    }

    _list->head = createNode(head_data);
    _list->tail = createNode(tail_data);

    if (_list->head && _list->tail != NULL) { _list->head->next = _list->tail; }
    
    return _list;
}

//?     FUNZIONI DI INSERIMENTO
void    insertHead(List *self, void *data)
{
    Node *_head = createNode(data);
    if (_head == NULL) {
        fprintf(stderr, "Errore di inserimento in Testa alla Lista\n");
        return;
    }

    _head->data = data;
    _head->next = self->head;

    self->head = _head;
}

void    insertTail(List *self, void *data)
{
    self->tail->next = createNode(data);
    if (self->tail->next == NULL) {
        fprintf(stderr, "Errore di inserimento in Coda alla Lista\n");
        return;
    }

    self->tail = self->tail->next;
}

void    insertHeadNode(List *self, Node *_node)
{
    _node->next = self->head;
    self->head = _node;
}

void    insertTailNode(List *self, Node *_node)
{
    self->tail->next = _node;
    self->tail = _node;
}

//?     FUNZIONI DI RIMOZIONE DEI NODI 
Node    *removeHead(List *self) 
{
    Node *_head = self->head;
    self->head = self->head->next;

    return _head;
}

Node    *removeTail(List *self)
{
    Node *_tail = self->tail;
    Node *current = self->head;

    while (current->next->next) { current = current->next; }
    self->tail = current;
    self->tail->next = NULL;

    return _tail;
}

Node    *removeNode(List *self, Node *_node)
{
    Node *current = self->head;
    if (_node == self->head) { return removeHead(self); }
    while (current->next != _node) { current = current->next; }
    
    current->next = _node->next;
    return _node;
}

//?     FUNZIONI RI RESTITUZIONE
void    *getData(Node *self) 
{ 
    return self->data; 
}

Node    *getHead(List *self) 
{ 
    return self->head; 
}

Node    *getTail(List *self) 
{ 
    return self->tail; 
}

Node    *getNodeAt(List *self, int index)
{
    Node *current = self->head;
    while (current && --index > 0) { current = current->next; }

    return current;
}

Node    *getNodeBefore(List *self, Node *_node)
{
    Node *current = self->head;
    while (current && current->next != _node) { current = current->next; }
    
    return current;
}

Node    *getNodeAfter(Node *self) 
{ 
    return self->next;
}

//?     FUNZIONI DI RICERCA
Node    *findValue(List *self, void *data, int (*compare)(const void *a, const void *b))
{
    Node *current = self->head->next; 
    while (current && current->data != data) { current = current->next; }

    return current;
}

Node    *findMin(List *self, int (*compare)(const void *a, const void *b))
{
    Node *current = self->head;
    Node *min = self->head;
    
    while (current != NULL) {
        if (compare(current->data, min->data) < 0) { min = current; }
        current = current->next;
    }

    return min;
}

Node    *findMax(List *self, int (*compare)(const void *a, const void *b))
{
    Node *current = self->head->next;
    Node *max = self->head;

    while (current != NULL) {
        if (compare(current->data, max->data) > 0) { max = current; }
        current = current->next;
    }

    return max;
}

//?     FUNZIONI DI RILASCIO DELLA MEMORIA
void    deleteData(void *self) 
{ 
    free(self);
}

void    deleteNode(Node *self) 
{
    deleteData(self->data);
    free(self);
}

void    deleteList(List *self) 
{
    Node *current = NULL;

    while (self->head) {
        current = removeHead(self);
        deleteNode(current);    
    }

    free(self);
}

//?     FUNZIONI DI OUTPUT
void    printNode(Node *_node, void printData(const void *data))
{
    printData(_node->data);
}

void    printList(List *self, void printData(const void *data))
{
    Node *current = self->head->next;
    printNode(self->head, printData);
    
    while (current) {
        fprintf(stdout, ", ");
        printNode(current, printData);
        current = current->next;
    }
}