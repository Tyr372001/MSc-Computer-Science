/*
AIM: To get the reverse of a number inputted by the user using C language.
AUTHOR: Subhradeep Sarkar
PLATFORM: DEV C/C++
DATE: Friday, 23 August
*/

#include <stdio.h>
#include <math.h>

//Creating a function to find out the reverse of a number
int reverse(int number){
	
	int modulus;
	int reverse = 0;
	int i = 0;
	
	while(number != 0){
		
		modulus = number % 10;
		reverse = reverse * 10 + modulus;
		number = number/10;
	}
	
	return reverse;	
}


int main(){
	
	printf("Enter a number to get it's reverse : "); // Integrating I/O techniques
	int number;
	
	scanf("%d", &number);
	printf("\n \n");
	
	
	printf("The reverse of the number is: %d ", reverse(number));
}
