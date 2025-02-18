// Include Files
#include <stdio.h>
// Project Includes
#include "lab2header.h"
// Function Implementations

int reverse_number(int num)
{
	int reversed = 0;
        while(num > 0)
        {
	  reversed = reversed * 10 + num % 10;
	  num = num / 10;
        }
  return reversed; 

}

int even_odd(int num)
{
       return (num % 2 == 0);
}


int is_prime(int num)
{
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

