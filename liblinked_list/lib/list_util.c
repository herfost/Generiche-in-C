#include "list_util.h"

void sort(List *self, int (*compare)(const void *a, const void *b))
{
    Node *min = NULL;
    List *list = createList(NULL, NULL);

    while(self->head) {
        min = findMin(self, compare);
        min = min != self->head ? removeNode(self, min) : removeHead(self); 
        insertTailNode(list, min);
    }

    free(removeHead(list));
    free(removeHead(list));

    self->head = list->head;
    self->tail = list->tail;

    free(list);
}