/*
AIM: To explore all the Conditional Statements using C language.
AUTHOR: Subhradeep Sarkar from MSc First Year
PLATFORM: DEV C/C++
DATE: Friday, 23 August, 2024
*/


# include <stdio.h>

// A function that checks Equality of a number, an example of If-Else conditional statements
void checkEquality(int number_1, int number_2){
		
	if(number_1 == number_2){
		
		printf("The Numbers are Equal!!");
		
	}
	
	else{
		printf("Numbers are not Equal!!!");
	}
}

// A function that the greatest of 3 numbersr, an example of If-Else If conditional statements
void findMax(int number_1, int number_2, int number_3){
	
	if((number_1 > number_2)&(number_1 > number_3)){
		printf("%d is greater", number_1);
	}
	else if((number_2 > number_3)){
		printf("%d is greater", number_2);
	}
	else{
		printf("%d is grater", number_3);
	}
}

// A function that demonstrates an example of Only-If  conditional statements
void choiceCondition(int choice){
	
	if(choice == 11){
		
		printf("Congradulation you're very lucky!!!'");
		
	}
	
	if ((choice < 11) & (choice >= 0)){
		printf("You're partially Lucky'");
	}
	
	if((choice > 11) &(choice <= 100)){
		printf("You're not so lucky'");
	}
	
}


// A function that demonstrates an example of Nested If-Else  conditional statements
void greaterThan(int number_1, int number_2){
	
	if(number_1 == number_2){
		printf("Both numbers are same");
	}
	
	else{
		if(number_1 > number_2){
			printf("%d is greater by %d", number_1, (number_1 - number_2));
		}
		
		else{
			printf("%d is greater by %d", number_2, (number_2 - number_1));
		}
	}
	
}

int main(){
	
	checkEquality(12,13);
	
	printf("\n");
	printf("\n");
	
	
	checkEquality(15,15);
	

	printf("\n");
	printf("\n");
	
	findMax(13,10,22);
	
	printf("\n");
	printf("\n");
	
	choiceCondition(11);
	
	printf("\n");
	printf("\n");
	
	choiceCondition(45);
	
	printf("\n");
	printf("\n");
	
	greaterThan(13, 50);
	
	printf("\n");
	printf("\n");
	
	greaterThan(101,20);
	
	return 0;
}


