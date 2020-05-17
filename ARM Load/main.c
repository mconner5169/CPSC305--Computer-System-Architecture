#include <stdio.h>
#define LOOPS 3
extern void pbr_asm(int *p);
int main() {
    int x = 5;
    for (int i=0; i<LOOPS; i++) {
        printf("Enter a num: ");
        scanf("%d", &x);
        printf("%d\n", x+1);
        pbr_asm(&x);
        printf("%d\n", x);
    }

    return 0;
}
