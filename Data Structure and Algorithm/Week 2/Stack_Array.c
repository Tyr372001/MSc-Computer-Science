/*
	Author: Subhradeep Sarkar
	Date: 30/08/2024
	Aim: Implementation of Stack Data Structure using Arrays
 	Platform: Windows
  	Compiler: GNU C Compiler
	
	Description: Stack is a Linear data structure. It follows the 'Last In First Out' (LIFO) principle. Stack is implemented using Linked List and Arrays.
	
	Modules Names: isFull(), isEmpty(), push(), pop(), isPeek()
	Global Variables: stack_array[], stack_top
	
*/





// Including necessary header files
# include <stdio.h>
# include <conio.h>

// Defining the capacity of the stack as macro for easy manipulation of size of the stack
# define CAPACITY 10

// Initialising stack_array as a global variable
int stack_array[CAPACITY];

//Initialising the stack_top variable
int stack_top = -1;

/*
	Author: Subhradeep Sarkar
	Date: 30/08/2024
	Module Name: isFULL()
	Parameters: NA
	Return type: <integer>
	Local variables: NA
	Aim: To check if the Stack is Full or Not
*/

// Blueprint for isFull() function
int isFull(){
	
	// Condition for checking the fullness of the stack_array.
	if(stack_top == (CAPACITY-1)){
		
		// Returning 0 if stack_top reaches the stack_array capacity
		return 1;
	}
	else{
		
		// Returning 1 if the stack_top haven't reach the stack_array capacity
		return 0;
	}
}


/*
	Author: Subhradeep Sarkar
	Date: 30/08/2024
	Module Name: isEmpty()
	Parameters: NA
	Return type: <integer>
	Local variables: NA
	Aim: To check if the Stack is Empty or Not
*/
// Blueprint for isEmpty() function
int isEmpty(){
	
	// Condition for checking the Emptiness of the stack_array.
	if(stack_top == -1){
		
		// Returning 0 if stack_top reaches the stack_array's lower bounds
		return 1;
	}
	else{
		
		// Returning 1 if the stack_top haven't reach the stack_array's lower bounds
		return 0;
	}
	
}

/*
	Author: Subhradeep Sarkar
	Date: 30/08/2024
	Module Name: push()
	Parameters: <interger> element
	Return type: <void>
	Local variables: NA
	Aim: To add new elements to the satck
*/
// Blueprint for push() function of the Stack
void push(int element){
	
	// Checking if the stack_array is full or not
	if(isFull()){
		printf("Element Cannot be Added. \n Stack is FULL!!!\n");
	}
	
	// Condition for adding new element to the stack
	else{
		stack_array[++stack_top] = element;
	}
	
}

/*
	Author: Subhradeep Sarkar
	Date: 30/08/2024
	Module Name: pop()
	Parameters: NA
	Return type: <void>
	Local variables: <integer> temp
	Aim: To remove existing elemnt in Stack
*/
// Blueprint for pop() function of the Stack
void pop(){
	
	// Checking if the stack_array is empty or not
	if(isEmpty()){
		printf("No element to pop. \nStack is EMPTY!!! \n");
	}
	
	// Condition for popping existung elemnts
	
	else{
		
		// Initialising a temp variable for extracting the stack_top element while replacing it with 0 which is the integer default value;
		int temp = stack_array[stack_top];
		stack_array[stack_top] = 0;
		
		// Decrementing the satck_top for correct indexing of the top the elemnt
		stack_top--;
		
		printf("%d  is successfully popped from the Stack", temp);
		
	}
	
	
}

// Declaring the main() function
int main(){
	
	// push() allows to add new element to the stack
	void push(int element);
	
	// pop() function removes an existing element from the stack
	void pop();
	
	// isPeek() function allows the user to glimplse at the top element of the stack
	int isPeek();
	
	// isEmpty() function checks for Emptiness of Stack
	int isEmpty();
	
	// isFull() function checks if the stack is full or not
	int isFull();
	
	
	// Defining a looped user-friven menu for Stack Manipulation
	
	// choice variable for choosing options aviable
	int choice;
	
	// Defining an user's entry controlled loop 
	while(1){
		// Giving user aviable choices for Stack Manipulation
		printf("Choose the given options to use the following: \n\n \t 1. For pushing elemnt to the stack. \n \t 2. For popping element to the stack. \n \t -1. To exit from the program.");
		printf("\n");
		// Reading data from the user
		
		scanf("%d", &choice);
		
		// Defing a series of if-esle if for the Menu
		
		if(choice == 1){
			
			// Requesting Element that must be pushed into the stack_array
			int element;
			printf("Enter the Element <integer datatype>: ");
			scanf("%d", &element);
			
			printf("\n");
			
			push(element);
			
			printf("%d is successfully pushed into Stack \n \n", element);
		}
		
		else if(choice == 2){
			// Using pop() function to pop element from the stack_array
			
			pop();
			printf("\n \n");
		}
		
		else if(choice == -1){
			
			// Condition to exit the loop when satisfied
			
			break;
		}
		
		else{
			// Setting a condition for Default choice
			
			printf("Invalid Choice!!! Please try again \n");
			printf("\n");
		}
			
	}// Parsing End for While Loop
}

// End of the Program

