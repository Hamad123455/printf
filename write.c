#include "main.h"

int _write(int v) {
    char b[20];
    int l = 0;
    int i, j, k = 0;

    if (v < 0)
    {
	    v = -v;
	    k = 1;
    }
    
    do {
        b[l++] = '0' + v % 10;
        v /= 10;
    } while (v != 0);

    if (k == 1)
    {
	    b[l++] = '-';
    }

    for (i = 0, j = l - 1; i < j; i++, j--) {
        char temp = b[i];
        b[i] = b[j];
        b[j] = temp;
    }

    write(1, b, l);
    return (l);
}
