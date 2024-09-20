# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	
	int data;
	struct node *next;	

}node;

node *front = NULL;
node *rear = NULL;

node *createNode(int data){
	
	node *temp = (node*)malloc(sizeof(node));
	
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

void enqueue(int data){
	
	node *temp = createNode(data);
	
	if((front == NULL)&&(rear == NULL)){
		
		front = rear = temp;
		
	}
	else{
		
		rear->next = temp;
		rear = temp;
	}
}

int dequeue(){
	
	if(front == NULL){
		printf("Queue is Empty!!!\n");
	}
	
	else{
		node *temp = front;
		front = front->next;
		
		int discarded_data = temp->data;
		free(temp);
		
		return discarded_data;
	}	
}

void displayQueue() {
    node *temp = front;
    
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


int main(){
	
	enqueue(55);
	enqueue(66);
	enqueue(88);
	enqueue(77);
	
	 printf("Queue contents: ");
    displayQueue(); // Call display function to show queue contents
    
    int poppedValue = dequeue();
    printf("Dequeued value: %d\n", poppedValue);
    
    printf("Queue after dequeue: ");
    displayQueue(); // Display again after dequeing
    
    poppedValue = dequeue();
    printf("Dequeued value: %d\n", poppedValue);
    
    printf("Queue after dequeue: ");
    displayQueue();
}
