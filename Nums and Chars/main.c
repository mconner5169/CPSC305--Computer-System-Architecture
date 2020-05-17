#include <stdio.h>
#include <stdlib.h>
#include "rawdouble.h"
#include "convert.h"

int global = 1;

int main() {

    int local = 1;
    char line[100];
    int local_after_line = 1;
    int *heap = malloc(sizeof(int));
    *heap = 1;
    printf("Observing Addresses Section.\n");
    printf("global address: %p\n", &global);
    printf("local address: %p\n", &local);
    printf("local after line address: %p\n", &local_after_line);
    printf("heap address: %p\n", heap);
    printf("main address: %p\n", main);
    printf("Observe the addresses, enter to continue: ");
    fgets(line, 100, stdin);

    printf("\n\nObserving Integers Section.\n");
    char char_fifty = 50;
    char char_minus50 = -50;
    int int_fifty = 50;
    int int_minus50 = -50;
    printf("char_fifty:   %d, 0x%08x\n", char_fifty, char_fifty);
    printf("~char_fifty+1:   %d, 0x%08x\n", ~char_fifty+1, ~char_fifty+1);
    printf("char_minus50:  %d, 0x%08x\n", char_minus50, char_minus50);
    printf("int_fifty:   %d, 0x%08x\n", int_fifty, int_fifty);
    printf("~int_fifty+1:   %d, 0x%08x\n", ~int_fifty+1, ~int_fifty+1);
    printf("int_minus50:  %d, 0x%08x\n", int_minus50, int_minus50);
    char char_g = 125;
    char char_h = 125;
    char_fifty = char_g + char_h;
    printf("char_fifty overflows 125+125 %d %d\n", char_fifty, char_g + char_h);
    int_fifty = char_g + char_h;
    printf("int_fifty ok on 125 + 125: %d %d\n", int_fifty, char_g + char_h);
    printf("Observe the values, enter to continue: ");
    fgets(line, 100, stdin);
    
    printf("\n\nStudy convert.c and convert.h Section.\n");
    printf("32 Binary: %s Base 3: %s Octal: %s Hex: %s\n", convert(32, 2), convert(32,3), convert(32,8), convert(32,16));
    printf("65535 Binary: %s Base 3: %s Octal: %s Hex: %s\n", convert(0xffff, 2), convert(0xffff,3), convert(0xffff,8), convert(0xffff,16));
    printf("Study convert.c and convert.h and observe the converted values, enter to continue: ");
    fgets(line, 100, stdin);
    
    printf("\n\nchar, int, string Section.\n");
    char g = 'g';
    char h = 'h';
    char *address_of_g = &g;
    char *address_of_h = &h;
    char ghij[5] = "ghij\0";
    char *address_of_ghij = ghij;
    int *ghij_int = (int *)address_of_ghij;
    printf("g:       %d, 0x%08x, %c\n", g, g, g);
    printf("adr g:   %d, 0x%08x\n", (int)address_of_g, (int)address_of_g);
    printf("h:       %d, 0x%08x, %c\n", h, h, h);
    printf("adr h:   %d, 0x%08x\n", (int)address_of_h, (int)address_of_h);
    printf("*(adr g)  : %d, 0x%08x, %c\n", *(address_of_g), *(address_of_g), *(address_of_g));
    printf("*(adr g+1): %d, 0x%08x, %c\n", *(address_of_g+1), *(address_of_g+1), *(address_of_g+1));
    printf("*(adr g-1): %d, 0x%08x, %c\n", *(address_of_g-1), *(address_of_g-1), *(address_of_g-1));
    printf("vals ghij[0],[1],[2],[3]: 0x%08x, 0x%08x, 0x%08x, 0x%08x\n", (int)*address_of_ghij, (int)*(address_of_ghij+1), (int)*(address_of_ghij+2), (int)*(address_of_ghij+3));
    printf("adrs ghij[0],[1],[2],[3]: 0x%08x, 0x%08x, 0x%08x, 0x%08x\n", (int)address_of_ghij, (int)address_of_ghij+1, (int)address_of_ghij+2, (int)address_of_ghij+3);
    printf("*(adr ghij_int): %d, 0x%08x\n", *ghij_int, *ghij_int);
    printf("ghij: %s\n", ghij);
    printf("ghij using address_of_ghij: %s\n", address_of_ghij);
    
    printf("Print char * using a pointer in for loop.\n");
    char str[] = "Raspberry Pi";
    for (char *p = str; *p != 0; p++)
        printf("%c: %d\n", *p, *p); 
        
    char somestr[] = { 82, 97, 115, 112, 98, 101, 114, 114, 121, 32, 80, 105, 0 };
    printf("somestr filled with numbers: %s\n", somestr);
    printf("Observe the values, enter to continue: ");
    fgets(line, 100, stdin);
    

    
    printf("\n\nFloating point Section.\n");
    double y=.1;    // y is .1+.1+.1+.1+.1+.1+.1+.1+.1+.1, which should be 1.0
                    // y is not 1
                    // IEEE Floating Point does not represent .1 exactly
    y=y+.1; // .2
    y=y+.1; // .3
    y=y+.1; // .4
    y=y+.1; // .5
    y=y+.1; // .6
    y=y+.1; // .7
    y=y+.1; // .8
    y=y+.1; // .9
    y=y+.1; // 1.0
    double one = 1.0; // one is 1.0 -- really 1.0, whereas y is really close to 1.0
    // 1.0 when normalized is 0b1.0 * 2**0
    // Since IEEE has hidden bit, the mantissa is 0, which represents 1.0
    // Since IEEE has an 11-bit biased exponent, the exponent is 0x3FE, which is 0
    printf("1.0 normalized is 0b1.0 * 2**0\n");
    printf("64-bit IEEE 745 has a hidden bit, so the mantissa for 1.0 is 0.\n");
    printf("64-bit IEEE 745 has 11-bit exponent, 1023 or 0x3ff is 0.\n");
    printf("Next two lines are the variable double one = 1.0 in binary/hex\n");
    print_raw_double_binary(one);
    print_raw_double_hex(one);     
    printf("Next two lines are the variable double y = .1 + .1 ... + .1 in binary/hex\n");
    printf("64-bit IEEE 745 has 11-bit exponent, 1022 or 0x3fe is -1, i.e., 2**-1, which is .5.\n");
    printf("64-bit IEEE 745 has 52-bit mantissa, which is all 1's - really close to 2.0.\n");
    printf(".5 times something really close to 2.0 is something really close to 1.0.\n");
    print_raw_double_binary(y);
    print_raw_double_hex(y);   
    printf("Next line is y printed with printf - it shows 1.0 - it is really close.\n");
    printf("y with percentlf: %lf\n", y);

    double one_half = .5; 
    double *ptr_one_half = &one_half;
    int *ptr_int = (int *)&one_half;
    printf("%f 0x%08x 0x%08x \n", *ptr_one_half, *ptr_int, *(ptr_int+1));
    printf("%d 0x%08x 0x%08x \n", *ptr_int, (unsigned int)ptr_int, (unsigned int)(ptr_int+1));
    
    printf("0.5 normalized is 0b1.0 * 2**-1\n");
    printf("Next two lines are the variable double one_half = .5 in binary/hex\n");
    print_raw_double_binary(one_half);
    print_raw_double_hex(one_half);    
    printf("Next two lines are the variable -one_half in binary/hex\n");
    print_raw_double_binary(-one_half);
    print_raw_double_hex(-one_half);

    printf("Observe the values, enter to continue: ");
    fgets(line, 100, stdin);
    
    printf("\n\nBitwise operator Section. Ctl-C to exit\n");
    unsigned int a, b;
    
    while (1) {
        printf("Enter two hex numbers: ");
        scanf("%08x %08x", &a, &b);

        printf("0x%08x  & 0x%08x = 0x%08x\n", a, b, a & b);
        printf("0x%08x  | 0x%08x = 0x%08x\n", a, b, a | b);
        printf("0x%08x  ^ 0x%08x = 0x%08x\n", a, b, a ^ b);
        printf("0x%08x << 0x%08x = 0x%08x\n", a, b, a << b);
        printf("0x%08x >> 0x%08x = 0x%08x\n", a, b, a >> b);
        printf("~0x%08x = 0x%08x\n", a, ~a);
        printf("~0x%08x = 0x%08x\n", b, ~b);
        printf("two-complement of 0x%08x: %d, 0x%08x\n", a, ~a+1, ~a+1);
    }

}
