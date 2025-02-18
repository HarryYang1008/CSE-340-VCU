#include <stdio.h>
#include "lab2header.h"

int main(void) 
{ 
	char ch = 'N'; /* variable to accept the user's choice, 
										N represents the condition not to exit from the program */ 
        int num, prime; /* variable to accept a number */ 
	while( (ch != 'Y') && (ch != 'y') ) 
	{ 

		printf("Enter R to reverse the digits of the number \n"); 
		printf("Enter E to determine if the number is even or odd \n"); 
		printf("Enter P to determine if the number is prime \n"); 
		printf("Enter Y or y to exit the program\n"); 
		printf("Enter your choice: "); 

		scanf("%c", &ch); 
		while(getchar() != '\n'); /*clears the input buffer, alternatively 
																you can use fflush*(stdin)*/

		switch(ch) 
		{ 
			case 'R': case 'r': 
				printf("Enter the number to be reversed:\n"); 
				scanf("%d", &num);
				while(getchar() != '\n'); 
				break; 

			case 'E': case 'e': 
				printf("Enter the number to check if it is even or odd:\n"); 
               			scanf("%d", &num); 
				while(getchar() != '\n');
			       if (even_odd(num))
                                 printf("Your number is even.\n");
                               else
                                 printf("Your number is odd.\n");	
				break; 

			case 'P': case 'p': 
				printf("Enter the number to check if it is prime or not:\n"); 
				scanf("%d", &num); 
				while(getchar() != '\n'); 
			        prime = is_prime(num);
                                if (prime)
                                   printf("Your number is prime.\n");
                                else
                                   printf("Your number is not  prime.\n");
				break; 

			case 'Y': case 'y': 
				printf("Exiting the program.\n\n"); 
				break;

			default: 
				printf("You have entered a wrong choice. Try again\n"); 
				break; 
		} /* switch */
	} /* while */ 
	return 0; 
} /* main */ 
