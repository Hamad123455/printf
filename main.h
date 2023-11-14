#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd>

int _printf(const char *format, ...);
void reverse(char str[], int length);
char* citoa(int num, char* str, int base);

#endif
