#include <stdlib.h>
#include <stdio.h>
#include "convert.h"

/*
 * Converts an int to a char* of the selected base.
 * Supports bases 2 to 16.
 * mallocs memory for the returned string, which user must free
 */

char lookup[16] = "0123456789ABCDEF";
char prefix[17] = "00btqcsvondewTQCx";

char *convert(int n, int base) {
    if (base < 2 || base > 16)
        return NULL;
    int digit = 0, digits_in_n = 0, tn = n;
    while (n != 0) {
        digit = n % base;    // modulo
        n = n / base;        // integer division
        digits_in_n++;
    }
    
    digits_in_n += 2;        // +2 for prefix
    char *ans = malloc(digits_in_n + 1); // +1 for \0
    ans[0] = 0x30;           // ASCII 0
    ans[1] = prefix[base];
    ans[digits_in_n--] = '\0';
    n = tn;
    while (n != 0) {
        digit = n % base;    // modulo
        n = n / base;        // integer division
        ans[digits_in_n--] = lookup[digit];
    }
    
    return ans;
}
