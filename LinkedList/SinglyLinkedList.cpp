#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next; 
};

Node* generateNode(int data) {
    struct Node* temp = new Node;
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

void printLinkedList(Node* node) {
    while(node != NULL) {
        cout << node -> data;
        node = node -> next;
    }
}

void addNodeToFront(Node** head, Node* node) {
    node -> next = (*head);
    *head = node;
}

void addNodeToEnd(Node* head, Node* node) {
    while(head -> next != NULL) {
        head = head -> next;
    }
    head -> next = node;
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
    struct Node* frontNode = generateNode(40);
    addNodeToFront(&head, frontNode);
    struct Node* backNode = generateNode(50);
    addNodeToEnd(head, backNode);
    printLinkedList(head);

    return 0;
}