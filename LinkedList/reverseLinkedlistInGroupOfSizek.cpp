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

struct Node* reverseK(Node* head, int k) {
    if(head == NULL || k == 1) {
        return head;
    }

    struct Node* dummy = new Node(0);
    dummy -> next = head;
    struct Node* pre = dummy;
    struct Node* curr = dummy;
    struct Node* nex = dummy;
    int count = 0;

    while(curr -> next != NULL) {
        count++;
        curr = curr -> next;
    }

    while(count >= k) {
        curr = pre -> next;
        nex = curr -> next;

        for(int i = 0; i < k - 1; i++) {
            curr -> next = nex -> next;
            nex -> next = pre -> next;
            pre -> next = nex;
            nex = curr -> next;
        }

        pre = curr;
        count -= k;
    }

    return dummy -> next;
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

    struct Node* result = reverseK(head -> next, k);
    printLinkedList(result);
    return 0;
}