/*
 * Converts an int to a char* of the selected base.
 * Supports bases 2 to 16.
 * mallocs memory for the returned string, which user must free
 */

char * convert(int n, int base);
