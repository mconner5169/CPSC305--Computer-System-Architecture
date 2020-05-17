/***********************************************************/
/* rawdouble.c: Functions to access and print the raw      */
/*              contents of an IEEE double floating-point  */
/*              variable                                   */
/*                                                         */
/* Rick Regan, https://www.exploringbinary.com             */
/*                                                         */
/***********************************************************/
#include "stdio.h"
#include "rawdouble.h"

void print_raw_double_binary(double d)
{
 unsigned long long *double_as_int = (unsigned long long *)&d;
 int i;
 printf("sign: ");
 for (i=0; i<=63; i++)
   {
    if (i==1)
      printf(" exp: "); // Space after sign field
    if (i==12)
      printf(" mant: "); // Space after exponent field

    if ((*double_as_int >> (63-i)) & 1)
      printf("1");
    else
      printf("0");
   }
 printf("\n");
}

void parse_double(double d, 
                  unsigned char *sign_field,
                  unsigned short *exponent_field,
                  unsigned long long *fraction_field)
{
 unsigned long long *double_as_int = (unsigned long long *)&d;

 *sign_field = (unsigned char)(*double_as_int >> 63);
 *exponent_field = (unsigned short)(*double_as_int >> 52 & 0x7FF);
 *fraction_field = *double_as_int & 0x000FFFFFFFFFFFFFULL;
}

void print_raw_double_hex(double d)
{
 unsigned char sign_field;
 unsigned short exponent_field;
 unsigned long long fraction_field;

 parse_double(d,&sign_field,&exponent_field,&fraction_field);

 printf("sign: %X exp: %11X mant: %llX\n",sign_field,exponent_field,fraction_field);
}
