#include <stdio.h>
#include "lib/list_util.h"
#include "lib/list.h"
#include "lib/data.h"

int main(int argc, char **argv)
{
    fprintf(stdout, "\n");
    List *list_s = createList(newString("Sigma"), newString("Beta"));
    char *registro[] =
    {   
        "Zeta",
        "Gamma",
        "Feta",
        "Epsylon",
        "Py",

    };  int size = sizeof(registro) / sizeof(char *);

    for (int i = 0; i < size; ++i) { insertTail(list_s, newString(registro[i])); }

    fprintf(stdout, "Lista inserita: "); printList(list_s, printString); fprintf(stdout, "\n");
    sort(list_s, compareString);
    fprintf(stdout, "Lista ordinata: "); printList(list_s, printString); fprintf(stdout, "\n");

    fprintf(stdout, "\n");

    List *list_i = createList(newInt(9), newInt(8));
    for (int i = 7; i > 0; --i) { insertTail(list_i, newInt(i)); }

    fprintf(stdout, "Lista inserita: "); printList(list_i, printInt); fprintf(stdout, "\n");
    sort(list_i, compareInt);
    fprintf(stdout, "Lista ordinata: "); printList(list_i, printInt); fprintf(stdout, "\n");

    fprintf(stdout, "\n");
    return 0;
}