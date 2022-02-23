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

void printLinkedList(Node* head) {
    struct Node* curr = head;

    while(curr != NULL) {
        cout << curr -> data << " ";
        curr = curr -> next;
    }
}

struct Node* rotateKTimes(Node* head, int k) {
    if(head == NULL || k == 0) {
        return head;
    }

    struct Node* curr = head;
    int count = 0;
    while(curr -> next != NULL) {
        curr = curr -> next;
        count++;
    }
    count++;
    k = k % count;
    curr -> next = head;
    k = count - k;
    curr = head;
    for(int i = 0; i < k - 1; i++) {
        curr = curr -> next;
    }

    head = curr -> next;
    curr -> next = NULL;

    return head;
}

int main() {
    int n;
    cin >> n;
    struct Node* head = new Node(0);
    struct Node* curr = head;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        struct Node* node = new Node(temp);
        curr -> next = node;
        curr = curr -> next;
    }

    int k;
    cin >> k;

    struct Node* result = rotateKTimes(head -> next, k);
    printLinkedList(result);

    return 0;
}