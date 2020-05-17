#include <stdio.h>
extern int name_asm();
extern int name_asm2();
int main() {
    printf("Gust\n");
    int n = name_asm();
    char name[5] = "1234";
    name[0] = n >> 24;
    name[1] = (n >> 16) & 0xff;
    name[2] = (n >> 8) & 0xff;
    name[3] = n & 0xff;
    name[4] = '\0';
    printf("%s\n", name);
    n = name_asm2();
    name[0] = n >> 24;
    name[1] = (n >> 16) & 0xff;
    name[2] = (n >> 8) & 0xff;
    name[3] = n & 0xff;
    printf("%s\n", name);
    return 0;
}
