/* This allows the user to set or modify short and long integers and then 
 *    examine the results in both decimal and binary format.  
 *           
 *              Programmer:  Henry Walker, Grinnell College
 *                 Written in C by Henry Walker (January 28, 2005)
 *                    Last revised by Henry Walker (January 30, 2005)
 *                       print_binary revised by Jerod Weinman (January 4, 2019)
 *                       */

#include <stdio.h>

int bitwise_add_one(int number) {
    int mask = 1;  // This mask represents the bit we're going to add to

    // We propagate the carry using XOR and AND
    while (number & mask) {
        number = number ^ mask;  // Flip the bit (this handles the addition)
        mask = mask << 1;        // Move to the next bit to propagate the carry
    }

    number = number ^ mask;  // Finally, flip the bit where there is no carry
    return number;
}

void
print_binary (int digits, int number);

int
main (void)
{ 
  short short_int = 1;
  int   inte = 1;
  int number;
  char option;

  printf ("\n");
  printf ("This program allows experimentation with different sizes of integers\n\n");
  printf ("Initial integer values:           decimal                       binary\n");
  printf ("   Short (16-bit) integer:%13hd                   ", short_int);
  print_binary (16, short_int);
  printf ("\n");
  printf (" Regular (32-bit) integer:%13d   ", inte);
  print_binary (32, inte);
  printf ("\n\n");

  while (1) 
    {
      printf ("Menu Options\n");
      printf ("  I - initialize each number to a value you have entered\n");
      printf ("  A - add 1 to each integer\n");
      printf ("  S - subtract 1 from each number\n");
      printf ("  M - multiple each number by 2\n");
      printf ("  D - divide each number by 2\n");
      printf ("  Q - Quit\n");
      printf ("Enter option:  ");
      scanf(" %c", &option);

      switch (option)
        {
        case 'i':
        case 'I':
          printf ("   Enter value that will be assigned to each integer:  ");
          scanf ("%d", &number);
          short_int = (short) number;
          inte      = number;
          break;
        case 'a':
        case 'A':
          short_int = (short) bitwise_add_one(short_int);
          inte = bitwise_add_one(inte);
          break;
        case 's':
        case 'S':
          short_int -= (short) 1;
          inte      -= 1;
          break;
        case 'm':
        case 'M':
          short_int *= (short) 2;
          inte      *= 2;
          break;
        case 'd':
        case 'D':// Divide by 2 using right shift
            short_int = (short) (short_int >> 1);
            inte = inte >> 1;
            break;
        case 'q':
        case 'Q':
          printf ("Program terminated\n");
          return 0;
          break;
        default: printf ("Unrecognized option -- please try again\n");
          continue;
        } // switch
      printf ("Resulting integer values          decimal                       binary\n");
      printf ("   Short (16-bit) integer:%13hd                   ", short_int);
      print_binary (16, short_int);
      printf ("\n");
      printf (" Regular (32-bit) integer:%13d   ", inte);
      print_binary (32, inte);
      printf ("\n\n");

    } // while(1)
} // main

void
print_binary (int digits, int number)
{
  /* this function prints the bit representation of number, assuming that
 *      digits gives the number of bits in the original declaration of number
 *        
 *             when called with short ints, digits should be 15 (at least on Pentium 4
 *                  machines) when called with regular ints, digits should be 32
 *                    */
  for (int position = digits-1 ; position>= 0 ; position--)
    printf ("%X", (number>>position) & 1 );
} // print_binary
