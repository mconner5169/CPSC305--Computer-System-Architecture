#include <stdio.h>
#define LOOPS 3
extern int add_asm(int x, int y);
int main() {
   int x=0, y=0, z=0, z1=0, z2=0;
   for (int i=0; i<LOOPS; i++) {
      printf(“Enter three nums: “);
      scanf("%d%d%d", &x, &y, &z);
      z1 = x + y - z;
      z2 = add_asm3(x,y,z);
      printf("%d\n", z1);
      printf("%d\n", z2);
   }
   return 0;
}
