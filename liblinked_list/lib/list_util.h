#ifndef LIST_UTIL_H_
#define LIST_UTIL_H_

#include <stdlib.h>
#include "list.h"

void sort(List *self, int (*compare)(const void *a, const void *b));

#endif // LIST_UTIL_H_