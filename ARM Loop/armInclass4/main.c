#include <stdio.h>
#define LOOPS 3
extern int sum1ton_asm(int x);
extern int sum1ton_asm2(int x);
int main() {
    int x=0, y=0, z=0, z1=0, z2=0;
    for (int i=0; i<LOOPS; i++) {
        printf(“Enter a num: “);
        scanf("%d", &x);
        int sum = 0;
        for (int i = 1; i < x; i++)
            sum += i;
        printf("%d\n", sum);
        sum = sum1ton_asm(x);
        printf("%d\n", sum);
        sum = sum1ton_asm2(x);
        printf("%d\n", sum);
    }
    return 0;
}
