#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

// Function to create a new node
node *createNode(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at a given index in a circular linked list
void insert_node_at_index(int data, int index) {
    node *newNode = createNode(data);

    // If inserting at index 0 (head)
    if (index == 0) {
        if (head == NULL) {
            // If the list is empty, point newNode to itself
            head = newNode;
            head->next = head; // Complete the circle
        } else {
            // If the list is not empty, insert at head
            newNode->next = head; // Point newNode to current head
            // Find the last node to update its next pointer
            node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Update last node's next to newNode
            head = newNode; // Update head to newNode
        }
        return;
    }

    // Traverse to find the position before the index to insert
    node *prev = head;
    for (int i = 0; i < index - 1; i++) {
        if (prev->next == head) { // If we reach back to head, index is out of bounds
            printf("Index out of bounds!\n");
            free(newNode); // Free allocated memory for new node
            return;
        }
        prev = prev->next; // Move to next node
    }

    // Insert newNode after prev
    newNode->next = prev->next; // Point newNode to next node
    prev->next = newNode; // Link previous node to newNode
}

// Function to delete a node at a given index in a circular linked list
void delete_node_at_index(int index) {
    if (head == NULL) {
        printf("Deletion of Empty List!! ERROR\n");
        return; // Exit if the list is empty
    }

    node *temp = head;

    // If deleting the head node
    if (index == 0) {
        // If there's only one node
        if (temp->next == head) {
            free(temp);
            head = NULL; // List becomes empty
            return;
        }

        // Find the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        // Update the last node's next pointer to skip the head
        temp->next = head->next;
        free(head); // Free memory of old head
        head = temp->next; // Update head to the next node
        return;
    }

    // Traverse to find the position before the index to delete
    node *prev = head;
    for (int i = 0; i < index; i++) {
        if (prev->next == head) { // If we reach back to head, index is out of bounds
            printf("Index out of bounds!\n");
            return;
        }
        prev = prev->next; // Move to next node
    }

    // Now `prev` is at the node just before the one we want to delete
    if (prev->next == head) { // If we're trying to delete the last node
        free(head); // Free memory of last node
        prev->next = head; // Update previous to point back to head
        return;
    }

    // Normal deletion case
    node *toDelete = prev->next; // Node to be deleted
    prev->next = toDelete->next; // Bypass the deleted node
    free(toDelete); // Free memory of deleted node
}

// Function to display the circular linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    node *temp = head;
    
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(back to %d)\n", head->data); // Indicate circular nature
}

// Example usage of insertion and deletion functions in circular linked list.
int main() {
    printf("Initial Circular List: ");
    
    insert_node_at_index(10, 0);  // Insert at index 0 (first element)
    displayList(); 

    insert_node_at_index(20, 1);  // Insert at index 1 (second element)
    displayList(); 

    insert_node_at_index(30, 1);  // Insert at index 1 (between first and second)
    
    printf("List after insertions: ");
    displayList(); 

    delete_node_at_index(0);       // Delete second element
    
    printf("List after deletion at index 0: ");
    displayList(); 

    delete_node_at_index(0);       // Delete first element
    
    printf("List after deletion at index 1: ");
    displayList(); 

    return 0;
}
