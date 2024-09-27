#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *createNode(int data) {
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    temp->data = data;
    temp->next = NULL;

    return temp;
}

node *insert_Node_at_index(int data, int index, node *head) {
    node *temp = createNode(data);

    if (head == NULL && index > 0) {
        printf("Cannot insert at index %d in an empty list!\n", index);
        free(temp); // Free allocated memory
        return head; // Return head unchanged
    }

    if (index == 0) {
        temp->next = head;
        return temp; // New head of the list
    }

    node *traverse = head;

    for (int i = 0; i < index - 1; i++) {
        if (traverse == NULL) {
            printf("Index out of bounds!\n");
            free(temp); // Free allocated memory
            return head; // Return head unchanged
        }
        traverse = traverse->next;
    }

    temp->next = traverse->next;
    traverse->next = temp;

    return head; // Return updated list head
}

node *delete_Node_at_index(int index, node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head; // Return unchanged head
    }

    node *toDelete = head;

    // Deleting the head node
    if (index == 0) {
        head = toDelete->next;
        free(toDelete);
        return head; // Return new head of the list
    }

    node *traverse = head;

    for (int i = 0; i < index - 1; i++) {
        if (traverse == NULL || traverse->next == NULL) {
            printf("Index out of bounds!\n");
            return head; // Return unchanged head
        }
        traverse = traverse->next;
    }

    toDelete = traverse->next;

    if (toDelete == NULL) {
        printf("Index out of bounds!\n");
        return head; // Return unchanged head
    }

    traverse->next = toDelete->next;
    free(toDelete);

    return head; // Return updated list head
}

void displayList(node *head) {
    node *temp = head;

    while (temp != NULL) {
        if (temp->next == NULL) {
            printf("%d", temp->data);
        } else {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
    }

    printf("\n");
}

node *mergeListAtIndex(node *head_1, node *head_2, int index) {
	if(head_2 == NULL) return head_1; // If second list is empty, return first list

	if(index == 0) { // If merging at the beginning
		node *temp = head_2;
		while(temp->next != NULL) { 
			temp = temp->next; 
		}
		temp->next = head_1;
		return head_2; // New head is now the second list
	}

	node *traverse = head_1;

	for(int i = 0; i < index - 1; i++) {
		if(traverse == NULL) { 
			printf("Index out of bounds!\n");
			return head_1; // Return unchanged first list
		}
		traverse = traverse->next;
	}

	node *temp = traverse->next; // Save the next node after the index
	traverse->next = head_2; // Link first list to second list

	while(head_2 && head_2->next != NULL) { 
		head_2 = head_2->next; 
	}
	
	if(head_2 != NULL) { 
		head_2->next = temp; // Link last node of second list to saved next node
	}

	return head_1; // Return updated first list
}

int main() {
	node *head1 = NULL; // Initialize the first linked list
	node *head2 = NULL; // Initialize the second linked list

	// Insert nodes into the first linked list
	head1 = insert_Node_at_index(10, 0, head1);
	head1 = insert_Node_at_index(20, 1, head1);
	head1 = insert_Node_at_index(30, 2, head1);
	printf("First List after insertion: ");
	displayList(head1);

	// Insert nodes into the second linked list
	head2 = insert_Node_at_index(40, 0, head2);
	head2 = insert_Node_at_index(50, 1, head2);
	head2 = insert_Node_at_index(60, 2, head2);
	printf("Second List after insertion: ");
	displayList(head2);

	// Ask user for the index to merge at
	int index;
	printf("Enter the index at which to merge the second list into the first: ");
	scanf("%d", &index);

	// Merge the two lists at the specified index and display the result
	head1 = mergeListAtIndex(head1, head2, index);
	printf("Merged List: ");
	displayList(head1);

	// Clean up memory before exiting program
	while(head1 != NULL) {
		node* temp = head1;
		head1 = head1->next;
		free(temp);
	}
	
	return 0;
}
