#include "main.h"

void _write(int value) {
    char buffer[20];
    int length = 0;
    int i, j, k = 0;

    if (value < 0)
    {
	    value = -value;
	    k = 1;
    }
    
    do {
        buffer[length++] = '0' + value % 10;
        value /= 10;
    } while (value != 0);

    if (k == 1)
    {
	    buffer[length++] = '-';
    }

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    write(1, buffer, length);
}
