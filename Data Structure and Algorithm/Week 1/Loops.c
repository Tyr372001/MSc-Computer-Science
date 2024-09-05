/*
AIM: To explore all the Loops (for, while, do-while) using C language.
AUTHOR: Subhradeep Sarkar
PLATFORM: DEV C/C++
DATE: Friday, 23 August
*/

# include <stdio.h>

// A Simple function using for loops that prints the table of a Given number.
void tableOfVersion_1(int number){
	
	for(int i = 1; i<=10; i++){
		
		printf("%d x %d = %d \n", number, i, (number*i));
		
	}
}

// The same functions of printing the table of a given number using while loops
void  tableOfVersion_2(int number){
	
	int i = 1;
	
	while(i <= 10){
		printf("%d x %d = %d \n", number, i, (number*i));
		
		i++;
	}
	
}

// A simple Example of do-while loop

void exampleDoWhile(int loopController){
	int i = 0;
	
	do{
		printf("CUTN DSA\n");
		i++;
	}while(i<loopController);
	
}

int main(){
	
	tableOfVersion_1(12);
	
	printf("\n");
	printf("\n");
	
	tableOfVersion_2(13);
	
	printf("\n");
	printf("\n");
	
	exampleDoWhile(5);
	
}
