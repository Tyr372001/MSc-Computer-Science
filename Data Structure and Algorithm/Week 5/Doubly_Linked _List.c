#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a doubly linked list
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

// Function to create a new node
node *createNode(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to insert a node at a given index in a doubly linked list
void insert_node_at_index(int data, int index) {
    node *newNode = createNode(data);

    // If inserting at index 0 (head)
    if (index == 0) {
        if (head == NULL) {
            head = newNode; // If the list is empty, set head to newNode
        } else {
            newNode->next = head; // Point newNode to current head
            head->prev = newNode; // Set current head's prev to newNode
            head = newNode; // Update head to newNode
        }
        return;
    }

    // Traverse to find the position before the index to insert
    node *current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) { // If we reach end of list, index is out of bounds
            printf("Index out of bounds!\n");
            free(newNode); // Free allocated memory for new node
            return;
        }
        current = current->next; // Move to next node
    }

    // Insert newNode after current
    if (current == NULL) { // If current is NULL, index was out of bounds
        printf("Index out of bounds!\n");
        free(newNode); // Free allocated memory for new node
        return;
    }

    newNode->next = current->next; // Point newNode to next node
    newNode->prev = current; // Link previous node to newNode

    if (current->next != NULL) { // If not inserting at the end
        current->next->prev = newNode; // Update next node's prev pointer
    }
    
    current->next = newNode; // Link current node to newNode
}

// Function to delete a node at a given index in a doubly linked list
void delete_node_at_index(int index) {
    if (head == NULL) {
        printf("Deletion of Empty List!! ERROR\n");
        return; // Exit if the list is empty
    }

    node *current = head;

    // If deleting the head node
    if (index == 0) {
        if (current->next != NULL) { // More than one element in the list
            head = current->next; // Update head to next node
            head->prev = NULL; // Set prev of new head to NULL
        } else { // Only one element in the list
            head = NULL; // List becomes empty
        }
        free(current); // Free memory of old head
        return;
    }

    // Traverse to find the position before the index to delete
    for (int i = 0; i < index; i++) {
        if (current == NULL) { // If we reach end of list, index is out of bounds
            printf("Index out of bounds!\n");
            return;
        }
        current = current->next; // Move to next node
    }

    if (current == NULL) { // If current is NULL, index was out of bounds
        printf("Index out of bounds!\n");
        return;
    }

    // Now `current` is at the node we want to delete
    if (current->prev != NULL) { 
        current->prev->next = current->next; // Bypass the deleted node from previous side
    }
    
    if (current->next != NULL) { 
        current->next->prev = current->prev; // Bypass the deleted node from next side
    }

    free(current); // Free memory of deleted node
}

// Function to display the doubly linked list forward and backward
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

// Example usage of insertion and deletion functions in doubly linked list.
int main() {
    
    insert_node_at_index(10, 0);  // Insert at index 0 (first element)
    displayList(); 

    insert_node_at_index(20, 1);  // Insert at index 1 (second element)
    
    displayList(); 

    insert_node_at_index(30, 1);  // Insert at index 1 (between first and second)
    
    printf("List after insertions: ");
    displayList(); 

    delete_node_at_index(1);       // Delete second element
    
    printf("List after deletion at index 1: ");
    displayList(); 

    delete_node_at_index(0);       // Delete first element
    
    printf("List after deletion at index 0: ");
    
   displayList(); 

   delete_node_at_index(0);       // Delete remaining element
    
   printf("List after deletion at index 0: ");
   displayList(); 

   return 0;
}
