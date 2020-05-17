#include <stdio.h>
#define LOOPS 3
extern int find_largest_asm(int *p, int n);
int find_largest(int *p, int n) {
    int l = p[0];
    for (int i = 0; i < n; i++)
        if (l < p[i]) 
			l = p[i];
    return l;
}
int main() {
    int a[] = {1, 100, 3, 5, 60};
    for (int i=0; i<LOOPS; i++) {
        a[1]++;
        printf("%d\n", find_largest(a,5));
        printf("%d\n", find_largest_asm(a,5));
    }

    return 0;
}
