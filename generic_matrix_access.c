#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(int)
#define I 2
#define J 2
#define SCAN scan_int
#define PRINT print_int

void scan_char(void *data) { scanf("%c", (char *)data); }
void scan_int(void *data) { scanf("%d", (int *)data); }
void scan_double(void *data) { scanf("%lf", (double *)data); }

void print_char(const void *data) { printf("%c", *(char *)data); }
void print_int(const void *data) { printf("%d", *(int *)data); }
void print_float(const void *data) { printf("%lf", *(float *)data); }

void insertMatrix(void *base, int ncols, int memsize, int rows, int cols, void (*scan)(void *)) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scan(base + (i * ncols + j) * memsize);
        }
    }
}

void outputMatrix(void *base, int ncols, int memsize, int rows, int cols, void (*print)(const void *)) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            print(base + (i * ncols + j) * memsize);
            printf(" ");
        }   printf("\n");
    }
}

int main()
{
    int matrix_int[3][3] = { 0 };

    insertMatrix(matrix_int, 3, SIZE, I, J, SCAN);
    outputMatrix(matrix_int, 3, SIZE, I, J, PRINT);

    return 0;
}