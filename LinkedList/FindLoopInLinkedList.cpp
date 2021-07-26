#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next; 
};

bool findLoopInLinkedList(Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while(slow && fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;

    head = new Node;
    second = new Node;
    third = new Node;

    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = fourth;
    fourth -> data = 40;
    fourth -> next = fifth;
    fifth -> data = 60;
    fifth -> next = second;

    if(findLoopInLinkedList(head)) {
        cout << "Loop Exists";
    }
    else {
        cout << "Loop Doesn't exists";
    }

    return 0;
}