/*

AIM: Implementation of Stack using Linked List
Author: Subhradeep Sarkar
Platform: DevC++
Compiler: GNU C Compiler
Modules: *createNode(), push(), pop()
Global Variable = <List pointer> top

*/

# include <stdio.h>
# include <stdlib.h>
# define SIZE 10

typedef struct node {
	
	int data;
	struct node *next;
	
}node;

node *top = NULL;

node *createNode(int data){
	
	node *temp = (node*)malloc(sizeof(node));
	
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

int getLength(){
	
	int counter = 0;
	
	node *temp = top;
	
	while(temp != NULL){
		
		temp = temp->next;
		counter ++;
	}
	
	return counter;
	
}

void push(int data){
	
	node *temp = createNode(data);
	
	if(getLength() == (SIZE-1)){
		
		printf("Stack Length Reached!! Stack Overflow");
		
	}
	
	else if(top == NULL){
		
		top = temp;
		
	}
	
	else{
		
		temp->next = top;
		top = temp;
		
	}
}

int pop() {
    if (top == NULL) { // Check if the stack is empty
    
        printf("Stack is empty! Stack Underflow!!");
        return -1; // Return an error value or handle it as needed
        
    }
    
    node *temp = top;
    top = top->next;
    
    int popped_data = temp->data;
    
    free(temp);
    
    return popped_data;
}


void displayStack() {
    node *temp = top;
    
    while(temp != NULL) { // Change condition to temp != NULL
        if(temp->next == NULL) {
            printf(" %d", temp->data); // Print last element without arrow
        } else {
            printf(" %d ->", temp->data); // Print elements with arrow
        }
        temp = temp->next;    
    }
    printf("\n"); // Optionally add a newline for better output formatting
}


int main() {
	
    push(12);
    push(13);
    push(14);
    push(15);
    push(16);
    push(17);
    push(18);
    
    printf("Stack contents: ");
    displayStack(); // Call display function to show stack contents
    
    int poppedValue = pop();
    printf("Popped value: %d\n", poppedValue);
    
    printf("Stack after popping: ");
    displayStack(); // Display again after popping
    
    poppedValue = pop();
    printf("Popped value: %d\n", poppedValue);
    
    printf("Stack after popping: ");
    displayStack();
    
    return 0; // Ensure main returns an integer
}

