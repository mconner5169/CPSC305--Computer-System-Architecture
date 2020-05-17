	.text
	.align 2
	.global add_sub_asm
add_sub_asm:

/* C equivalent
int add_sub_asm(int x, int y, int z) {
   if (x < 0)
      x = y - z;
else
      x = y + z;
return x; } */
