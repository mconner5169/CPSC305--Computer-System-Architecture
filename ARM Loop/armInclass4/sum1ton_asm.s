	.text
	.align 2
	.global sum1ton_asm
sum1ton_asm:

/* C equivalent
int sum1ton_asm(int x) {
   int sum = 0;
   for (int i = 1; i <= x; i++)
      sum += i;
   return sum;
} */
