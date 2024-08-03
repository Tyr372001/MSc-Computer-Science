
// Including all the necessary header files

#include<stdio.h> // For Input/Output
#include<string.h> // For String related operations


//Defining a function for Integer to Roman conversions
void intToRoman(int number, char *result){
	
	char *thousands[] = {" ", "M", "MM", "MMM"}; 									  // Defining pointer for roman numeral string for the place value of thousands
	char *hundreds[] = {" ", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; // Defining pointer for roman numeral string for the place value of hundreds
	char *tens[] = {" ", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};	  // Defining pointer for roman numeral string for the place value of tens
	char *ones[] = {" ", "I", "II" , "III", "IV", "V", "VI", "VII", "VIII", "IX"};	  // Defining pointer for roman numeral string for the place value of ones
	
	strcpy(result, thousands[number/1000]);				// Copies the appropriate thousands place Roman numeral to the result string
	strcat(result, hundreds[(number % 1000)/100]);		// Appends the appropriate hundreds place Roman numeral to the result string
	strcat(result, tens[(number % 100)/10]);			// Appends the appropriate tens place Roman numeral to the result string
	strcat(result, ones[number % 10]);					// Appends the appropriate ones place Roman numeral to the result string
}




int main(){ // Starting main()

	int num;	// Declaring a variable to store the Integer input from the user
	
	char roman[20] = " ";		// Declaring an array to store resulting roman numeral
	
	int flag = 1;   			// Flag variable for Loop Control
	
	while(flag){
		
		printf("Enter an Integer (Arabic Numerals) \n");
		scanf("%d", &num);
	
		if(num > 0 & num < 4000){  // Roman numerals beyond 3999 are not confirmed
		
			intToRoman(num, roman);	// Calling the above defined functions
			printf("Roman numeral: %s\n", roman);
		}
		else{
			printf("\n \n Number is Out of range!!! \nRange=[1,3999]\n"); // Defining the conditions and the range of the Roman Numerals
		}
		
		// Defining an user controlled Loop 	
		printf("Do you want to continue [1 = yes | 0 = no] = \t");   
		scanf("%d", &flag);
	
		printf("\n \n"); 
	}
	
	return 0;
}

// Ending main()

