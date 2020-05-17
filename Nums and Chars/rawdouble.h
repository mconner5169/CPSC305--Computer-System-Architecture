/***********************************************************/
/* rawdouble.h: Functions to access and print the raw      */
/*              contents of an IEEE double floating-point  */
/*              variable                                   */
/*                                                         */
/* Rick Regan, https://www.exploringbinary.com             */
/*                                                         */
/***********************************************************/
void print_raw_double_binary(double d);

void parse_double(double d, 
                  unsigned char *sign_field,
                  unsigned short *exponent_field,
                  unsigned long long *fraction_field);

void print_raw_double_hex(double d);
