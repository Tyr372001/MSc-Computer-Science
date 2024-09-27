/*
AIM = To Merge two Linked List. Join the second list to the end of the 1st list.
AUTHOR: Subhradeep Sarkar
Date = Friday, 2024, September
Platform: DevC++
Compiler: GNU C Compiler
*/

# include <stdio.h>
# include <stdlib.h>

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

node *mergeListByEnd(node *head_1, node *head_2) {
    
	if(head_1 == NULL) return head_2; // If first list is empty, return second list
	if(head_2 == NULL) return head_1; // If second list is empty, return first list
	
	node *temp = head_1;

	while(temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = head_2;

	return head_1; // Return merged list
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

	// Merge the two lists and display the result
	node *mergedHead = mergeListByEnd(head1, head2);
	printf("Merged List: ");
	displayList(mergedHead);

	// Clean up memory before exiting program
	while(mergedHead != NULL) {
		node* temp = mergedHead;
		mergedHead = mergedHead->next;
		free(temp);
	}
	
	return 0;
}
