#include "data.h"

int        *newInt(int data)
{
    int *_data = malloc(sizeof(int));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di int8_t\n");
        return NULL;
    }

    *_data = data;
    return _data;
}

int8_t     *newInt8(int8_t data)
{
    int8_t *_data = malloc(sizeof(int8_t));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di int8_t\n");
        return NULL;
    }

    *_data = data;
    return _data;
}

int16_t    *newInt16(int16_t data)
{
    int16_t *_data = malloc(sizeof(int16_t));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di int16_t\n");
        return NULL;
    }

    *_data = data;
    return _data;
}

int32_t    *newInt32(int32_t data)
{
    int32_t *_data = malloc(sizeof(int32_t));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di int32_t\n");
        return NULL;
    }

    *_data = data;
    return _data;
}

int64_t    *newInt64(int64_t data)
{
    int64_t *_data = malloc(sizeof(int64_t));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di int64_t\n");
        return NULL;
    }

    *_data = data;
    return _data;
}

char        *newChar(char data)
{
    char *_data = malloc(sizeof(char));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di char\n");
        return NULL;
    }

    *_data = data;
    return _data;
}


char        *newString(const char *data)
{
    char *_data = calloc(strlen(data), sizeof(char));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di blocco di memoria di stringa\n");
        return NULL;
    }

    strcpy(_data, data);
    return _data;
}

float       *newFloat(float data)
{
    float *_data = malloc(sizeof(float));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di float\n");
        return NULL;
    }

    *_data = data;
    return _data;
}

double      *newDouble(double data)
{
    double *_data = malloc(sizeof(double));
    if (_data == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria di double\n");
        return NULL;
    }

    *_data = data;
    return _data;
}

int         compareInt(const void *a, const void *b) { return *(int *)a - *(int *)b; }
uint8_t     compareInt8(const void *a, const void *b) { return *(int8_t *)a - *(int8_t *)b; }
uint8_t     compareInt16(const void *a, const void *b) { return *(int16_t *)a - *(int16_t *)b; }
uint8_t     compareInt32(const void *a, const void *b) { return *(int32_t *)a - *(int32_t *)b; }
uint8_t     compareInt64(const void *a, const void *b) { return *(int64_t *)a - *(int64_t *)b; }

uint8_t     compareChar(const void *a, const void *b) { return *(char *)a - *(char *)b; }
int         compareString(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }

uint8_t     compareFloat(const void *a, const void *b) { return *(float *)a - *(float *)b; }
uint8_t     compareDouble(const void *a, const void *b) { return *(double *)a - *(double *)b; }

void        printInt(const void *data) { fprintf(stdout, "%i", *(char *)data); }
void        printInt8(const void *data) { fprintf(stdout, "%hhi", *(char *)data); }
void        printInt16(const void *data) { fprintf(stdout, "%hi", *(short*)data); }
void        printInt32(const void *data) { fprintf(stdout, "%i", *(int*)data); }
void        printInt64(const void *data) { fprintf(stdout, "%lli", *(long long*)data); }

void        printChar(const void *data) { fprintf(stdout, "%c", *(char *)data); }
void        printString(const void *data) { fprintf(stdout, "%s", (char *)data); }

void        printFloat(const void *data) { fprintf(stdout, "%f", *(float *)data); }
void        printDouble(const void *data) { fprintf(stdout, "%lf", *(double *)data); }