	.text
	.align 2
	.global find_largest_asm
find_largest_asm:

/* C equivalent
int find_largest(int *p, int n) {
    int l = p[0];
    for (int i = 0; i < n; i++)
        if (l < p[i]) l = p[i]
    return l;
} */
