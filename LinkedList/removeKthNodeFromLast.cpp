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

Node* removeKthFromLast(Node* head, int k) {
    Node* start = new Node(0);
    start -> next = head;
    Node* slow = start;
    Node* fast = start;

    for(int i = 0; i < k; i++) {
        fast = fast -> next;
    }

    while(fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = slow -> next -> next;

    return start -> next;
}

int main() {
    int n;
    cin >> n;
    Node* org = new Node(0);
    Node* dummy = org;
    
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* temp = new Node(val);
        dummy -> next = temp;
        dummy = dummy -> next;
    }

    int k;
    cin >> k;

    Node* result = removeKthFromLast(org -> next, k);

    while(result != NULL) {
        cout << result -> data << " ";
    }

    return 0;
}