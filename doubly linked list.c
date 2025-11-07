#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Insert node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update the last node's next pointer and the new node's prev pointer
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert node at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    // If the list is not empty, update the previous pointer of the current head
    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Display list forward
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display list backward
void displayBackward(Node* head) {
    if (head == NULL) return;

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward and print each node's data
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Delete node by value
void deleteNode(Node** head, int value) {
    Node* temp = *head;

    // Search for node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If node with given value not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // If the node to be deleted is the head
    if (*head == temp) {
        *head = temp->next;
    }

    // Update previous node's next pointer
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Update next node's previous pointer
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Free memory
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

int main() {
    Node* head = NULL;

    // Insert nodes at the end and beginning
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);

    // Display the list forward and backward
    printf("List displayed forward:\n");
    displayForward(head);
    printf("List displayed backward:\n");
    displayBackward(head);

    // Delete a node and display the updated list
    deleteNode(&head, 15);
    printf("List after deleting 15:\n");
    displayForward(head);
    displayBackward(head);

    // Try to delete a non-existent value
    deleteNode(&head, 100); // Node with value 100 does not exist
    return 0;
}
