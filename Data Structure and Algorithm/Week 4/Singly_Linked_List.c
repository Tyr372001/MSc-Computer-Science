#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

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

void insert_Node_at_index(int data, int index) {
    node *temp = createNode(data);
    
    if (head == NULL && index > 0) {
        printf("Cannot insert at index %d in an empty list!\n", index);
        free(temp); // Free allocated memory
        return;
    }
    
    if (index == 0) {
        temp->next = head;
        head = temp;
        return;
    }

    node *traverse = head;
    
    for (int i = 0; i < index - 1; i++) {
        if (traverse == NULL) {
            printf("Index out of bounds!\n");
            free(temp); // Free allocated memory
            return;
        }
        traverse = traverse->next;
    }

    temp->next = traverse->next;
    traverse->next = temp;
}

void delete_Node_at_index(int index) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *toDelete = head;

    // Deleting the head node
    if (index == 0) {
        head = toDelete->next;
        free(toDelete);
        return;
    }

    node *traverse = head;

    for (int i = 0; i < index - 1; i++) {
        if (traverse == NULL || traverse->next == NULL) {
            printf("Index out of bounds!\n");
            return;
        }
        traverse = traverse->next;
    }

    toDelete = traverse->next;

    if (toDelete == NULL) {
        printf("Index out of bounds!\n");
        return;
    }

    traverse->next = toDelete->next;
    free(toDelete);
}

void displayList() {
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

// Example usage
int main() {
    insert_Node_at_index(10, 0);
    insert_Node_at_index(20, 1);
    insert_Node_at_index(30, 2);
    insert_Node_at_index(40, 3);
    printf("List after insertion: ");
    displayList();

    delete_Node_at_index(1);
    
    printf("List after deletion: ");
    displayList();
    
    return 0;
}
