#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    Node() {

    }
};

Node* mergeSortedLinkedLists(Node* A, Node* B) {
    Node* l1;
    Node* l2;
    Node* result;

    if(A -> data <= B -> data) {
        l1 = A;
        l2 = B;
    }
    else {
        l1 = B;
        l2 = A;
    }

    result = l1;

    while(l1 != NULL && l2 != NULL) {
        Node* temp = NULL;

        while(l1 != NULL && l1 -> data <= l2 -> data) {
            temp = l1;
            l1 = l1 -> next;
        }

        temp -> next = l2;

        Node* temp2 = l1;
        l1 = l2;
        l2 = temp2;
    }

    return result;
}

int main() {
    struct Node* A1 = new Node(5);
    struct Node* A2 = new Node(7);
    struct Node* A3 = new Node(9);
    struct Node* B1 = new Node(3);
    struct Node* B2 = new Node(4);
    struct Node* B3 = new Node(8);
    struct Node* B4 = new Node(10);

    A1 -> next = A2;
    A2 -> next = A3;
    A3 -> next = NULL;

    B1 -> next = B2;
    B2 -> next = B3;
    B3 -> next = B4;
    B4 -> next = NULL;

    struct Node* result = mergeSortedLinkedLists(A1, B1);

    while(result != NULL) {
        cout << result -> data << "\t";
        result = result -> next;
    }

}