#ifndef DATA_H_
#define DATA_H_
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

int        *newInt(int data);
int8_t     *newInt8(int8_t data);
int16_t    *newInt16(int16_t data);
int32_t    *newInt32(int32_t data);
int64_t    *newInt64(int64_t data);

char        *newChar(char data);
char        *newString(const char *data);

float       *newFloat(float data);
double      *newDouble(double data);

int         compareInt(const void *a, const void *b);
uint8_t     compareInt8(const void *a, const void *b);
uint8_t     compareInt16(const void *a, const void *b);
uint8_t     compareInt32(const void *a, const void *b);
uint8_t     compareInt64(const void *a, const void *b);

uint8_t     compareChar(const void *a, const void *b);
int         compareString(const void *a, const void *b);

uint8_t     compareFloat(const void *a, const void *b);
uint8_t     compareDouble(const void *a, const void *b);

void        printInt(const void *data);
void        printInt8(const void *data);
void        printInt16(const void *data);
void        printInt32(const void *data);
void        printInt64(const void *data);

void        printChar(const void *data);
void        printString(const void *data);

void        printFloat(const void *data);
void        printDouble(const void *data);

#endif // DATA_H_