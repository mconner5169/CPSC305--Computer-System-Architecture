#include <stdio.h>
#define LOOPS 3

extern int arrcpy_asm(int *p,int n);
int arrcpy(int *dst, int *src, int n) {
    for (int i = 0; i < n; i++)
        *dst++ = *src++;
}

int main() {
   int a[] = {1, 100, 3, 5, 60};
   int b[5], c[5];
   for (int i=0; i<LOOPS; i++) {
      a[1]++; arrcpy(b,a); arrcpy_asm(c,a);
      for (int j=0; j<5; j++)
         printf("%d %d\n", b[j], c[j]);
   }
   return 0; 
}
