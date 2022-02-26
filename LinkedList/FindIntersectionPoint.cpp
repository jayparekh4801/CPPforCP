#include <iostream>

using namespace std;

struct Node {
    struct Node* next;
    int data;

    Node(int x) {
        data = x;
        next = NULL;
    } 
};


struct Node* interSection(Node* A, Node* B) {
    struct Node* a = A;
    struct Node* b = B;

    while(a != b) {
        a = (a == NULL) ? a = b : a -> next;
        b = (b == NULL) ? b = a : b -> next;
    }

    return a;
}


int main() {
    int n1, n2;
    cin >> n1;
    cin >> n2;
    struct Node* head1 = new Node(0);
    struct Node* temp1 = head1;
    struct Node* head2 = new Node(0);
    struct Node* temp2 = head2;

    for(int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        struct Node* newNode = new Node(val);
        temp1 -> next = newNode;
        temp1 = temp1 -> next;
    }

    for(int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        struct Node* newNode = new Node(val);
        temp2 -> next = newNode;
        temp2 = temp2 -> next;
    }

    struct Node* curr = head1 -> next;

    for(int i = 0; i < n1 - 3; i++) {
        curr = curr -> next;
    }

    temp2 -> next = curr;



    struct Node* result = interSection(head1 -> next, head2 -> next);

    cout << result -> data;

    return 0;
}