	.text
	.align 2
	.global arrcpy_asm
arrcpy_asm:

/* C equivalent
void arrcpy(int *dst, int *src, int n) {
    for (int i = 0; i < n; i++)
        *dst++ = *src++;
}
} */
