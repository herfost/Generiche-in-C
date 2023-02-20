#include <stdlib.h>
#include <stdio.h>

struct array {
    void *base;
    int nmem;
    int memsize;

    void (*scan_type)(void *);
    void (*scan_array)(struct array *self);

    void (*print_type)(const void *);
    void (*print_array)(struct array *self);

    int (*compare)(const void *, const void *);
    void (*sort)(struct array *self);
};

void    scan_char(void *element);
void    scan_int(void *element);
void    scan_double(void *element);

void    print_char(const void *element);
void    print_int(const void *element);
void    print_double(const void *element);

int     compare_char(const void *a, const void *b);
int     compare_short(const void *a, const void *b);
int     compare_int(const void *a, const void *b);
int     compare_long(const void *a, const void *b);
int     compare_float(const void *a, const void *b);
int     compare_double(const void *a, const void *b);

void    swap(void *n, void *m, int memsize);
void    sort(
    void *base, 
    int nmem, int memsize, 
    int (*compare)(const void *, const void *)
);

struct  array * new_array (
    int nmem, int memsize,
    void (*scan_type)(void *),
    void (*print_type)(const void *),
    int (*compare)(const void *, const void *)
);

void    scan_array(struct array *self);
void    print_array(struct array *self);
void    sort_array(struct array *self);


int main()
{
    struct array *arr = new_array(
        5, 
        sizeof(int), 
        scan_int, print_int, 
        compare_int
    );

    printf("Input:\n"); 
    arr->scan_array(arr);
    
    printf("\nElementi inseriti:\n"); 
    arr->print_array(arr); 
    printf("\n");

    arr->sort(arr);
    printf("\nSort:\n");
    arr->print_array(arr);

    return 0;
}

void    scan_char(void *element) { scanf("%c", (char *)element); }
void    scan_int(void *element) { scanf("%d", (int *)element); }
void    scan_double(void *element) { scanf("%lf", (double *)element); }

void    print_char(const void *element) { printf("%c", *(char *)element); }
void    print_int(const void *element) { printf("%d", *(int *)element); }
void    print_double(const void *element) { printf("%lf", *(double *)element); }

int     compare_char(const void *a, const void *b) { return ( *(char *)a - *(char *)b ); }
int     compare_short(const void *a, const void *b) { return ( *(short *)a - *(short *)b ); }
int     compare_int(const void *a, const void *b) { return ( *(int *)a - *(int *)b ); }
int     compare_long(const void *a, const void *b) { return ( *(long *)a - *(long *)b ); }
int     compare_float(const void *a, const void *b) { return ( *(float *)a - *(float *)b ); }
int     compare_double(const void *a, const void *b) { return ( *(double *)a - *(double *)b ); }

void    swap(void *n, void *m, int memsize)
{
    char *byte_ptr_n = (char *)n;
    char *byte_ptr_m = (char *)m;

    for (int i = 0; i < memsize; ++i, ++byte_ptr_n, ++byte_ptr_m) {
        *byte_ptr_n ^= *byte_ptr_m;
        *byte_ptr_m ^= *byte_ptr_n;
        *byte_ptr_n ^= *byte_ptr_m;
    }
}

void    sort(void *base, int nmem, int memsize, int (*compare)(const void *, const void *))
{
    int not_ordered =   1;

    void *prev =        NULL;
    void *succ =        NULL;

    for (int i = 0; i < nmem && not_ordered; ++i) {     
        not_ordered = 0;
        for (int j = 1; j < nmem; ++j) {     
            prev = base + (j - 1) * memsize;
            succ = base + j * memsize;
            if (compare(prev, succ) > 0 ) { 
                swap(prev, succ, memsize);
                not_ordered = 1; 
            }
        }
    }
}

struct  array * new_array
(
    int nmem, int memsize,
    void    (*scan_type)(void *),
    void    (*print_type)(const void *),
    int     (*compare)(const void *, const void *)
) {
    struct array *array = malloc(sizeof(struct array));
    if (!array) return NULL;

    array->base = calloc(nmem, memsize);
    if (!array->base) { free(array); return NULL; }

    array->nmem =           nmem;
    array->memsize =        memsize;
    array->scan_type =      scan_type;
    array->print_type =     print_type;
    array->compare =        compare;
    array->scan_array =     scan_array;
    array->print_array =    print_array;
    array->sort =           sort_array;
}

void    scan_array(struct array *self)
{
    for (int i = 0; i < self->nmem; ++i) { self->scan_type(self->base + i * self->memsize); }
}

void    print_array(struct array *self)
{
    self->print_type(self->base);
    for (int i = 1; i < self->nmem; ++i) { printf(" "); self->print_type(self->base + i * self->memsize); }
}

void    sort_array(struct array *self) { sort(self->base, self->nmem, self->memsize, self->compare); }