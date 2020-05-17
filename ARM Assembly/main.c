#include <stdio.h>
#define LOOPS 3
extern int add_asm(int x, int y);
int main() {
   int x=0, y=0, z1=0, z2=0;
   for (int i=0; i<LOOPS; i++) {
      printf(“Enter two nums: “);
      scanf("%d%d", &x, &y);
      z1 = x + y;
      z2 = add_asm(x,y);
      printf("%d\n", z1);
      printf("%d\n", z2);
   }
   return 0;
}
