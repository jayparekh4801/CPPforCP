#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next; 
};

void printLinkedList(Node* node) {
    while(node != NULL) {
        cout << node -> data;
        node = node -> next;
    }
}

void reverseLinkedList(Node** head) {
    struct Node* curr = (*head);
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }    

    *head = prev;
}

int main() {

    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = new Node;
    second = new Node;
    third = new Node;

    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = NULL;

    reverseLinkedList(&head);
    printLinkedList(head);

    return 0;
}