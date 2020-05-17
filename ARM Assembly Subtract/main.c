#include <stdio.h>
#define LOOPS 3
extern int add_sub_asm(int x, int y, int z);
int main() {
    int x=0, y=0, z=0, z1=0, z2=0;
    for (int i=0; i<LOOPS; i++) {
        printf("Enter three nums: ");
        scanf("%d%d%d", &x, &y, &z);
        if (x < 0)
            z1 = y - z;
        else
            z1 = y + z;
        z2 = add_sub_asm(x,y,z);
        printf("%d\n", z1);
        printf("%d\n", z2);
    }
    return 0;
}
