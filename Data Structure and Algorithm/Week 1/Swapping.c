/*
AIM: To Swap two numbers using ponters in C language.
AUTHOR: Subhradeep Sarkar
PLATFORM: DEV C/C++
DATE: Friday, 23 August
*/

#include <stdio.h>

//Declaring the swapping functions
void swap(int *bucketVariable_1, int *bucketVariable_2){
	
	int temporaryVariable = *bucketVariable_1;
	*bucketVariable_1 = *bucketVariable_2;
	*bucketVariable_2 = temporaryVariable;	
}
// swapping using pointers doesn't need return values;

int main(){
	
	int number_1 = 13;
	int number_2 = 17;
	
	printf("Before Swapping: \n");
	printf("number_1 = %d and number_2 = %d", number_1, number_2);
	
	swap(&number_1, &number_2);
	
	printf("\n\n");
	
	printf("After Swapping: \n");
	printf("number_1 = %d and number_2 = %d", number_1, number_2);
}

//end of the program
