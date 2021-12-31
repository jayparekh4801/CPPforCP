#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

struct Node* result;

void reverseLinkedList(struct Node* head, struct Node* prev) {
    if(head == NULL) {
        result = prev;
        return;
    }
    
    struct Node* curr = head -> next;
    head -> next = prev;
    prev = head;
    reverseLinkedList(curr, prev);
}


int main() {
    struct Node* first = new Node(1);
    struct Node* sec = new Node(2);
    struct Node* thi = new Node(3);
    first -> next = sec;
    sec -> next = thi;

    reverseLinkedList(first, NULL);

    while(result != NULL) {
        cout << result -> data << " ";
        result = result -> next;
    }

    return 0;
}