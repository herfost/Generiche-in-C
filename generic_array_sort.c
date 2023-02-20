#include <stdlib.h>
#include <stdio.h>

#define N 10
#define SIZE sizeof(int)
#define SCAN scan_int
#define PRINT print_int

void    scan_char(void *data);
void    scan_int(void *data);
void    scan_double(void *data);
void    scan_array(void *base, int nmem, int memsize, void (*scan)(void *data));


void    print_char(const void *data);
void    print_int(const void *data);
void    print_double(const void *data);
void    print_array(void *base, int nmem, int memsize, void (*print)(const void *data));

int     compare_char(const void *a, const void *b);
int     compare_short(const void *a, const void *b);
int     compare_int(const void *a, const void *b);
int     compare_long(const void *a, const void *b);
int     compare_float(const void *a, const void *b);
int     compare_double(const void *a, const void *b);

void    swap(void *n, void *m, int memsize);
void    bubble_sort
(
    void    *base, 
    int     nmem, int memsize, 
    int     (*compare)(const void *, const void *)
);


int main()
{
    int *arr = calloc(N, SIZE);
    if (!arr) {
        fprintf(stderr, "calloc failed\nin LINE %d, file %s\n", __LINE__, __FILE__);
        return 1;
    }

    scan_array(arr, N, SIZE), SCAN);
    print_array(arr, N, SIZE, PRINT);

    return 0;
}

void    scan_char(void *data) { scanf("%c", (char *)data); }
void    scan_int(void *data) { scanf("%d", (int *)data); }
void    scan_double(void *data) { scanf("%lf", (double *)data); }
void    scan_array(void *base, int nmem, int memsize, void (*scan)(void *data))
{
    for (int i = 0; i < nmem; ++i) { scan(base + i * memsize); }
}

void    print_char(const void *data) { printf("%c", *(char *)data); }
void    print_int(const void *data) { printf("%d", *(int *)data); }
void    print_double(const void *data) { printf("%lf", *(double *)data); }
void    print_array(void *base, int nmem, int memsize, void (*print)(const void *data))
{
    for (int i = 0; i < nmem; ++i) { print(base + i * memsize); }
}

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

void    bubble_sort
(
    void   *base, 
    int     nmem,
    int     memsize, 
    int     (*compare)(const void *, const void *)
) {
    int     not_ordered =   1;

    void    *prev =         NULL;
    void    *succ =         NULL;

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
