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

struct Node* reverse(Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;

    while(curr != NULL) {
        struct Node* nex = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nex;
    }

    return prev;
}

bool isPalindrome(Node* head) {
    if(head == NULL) {
        return false;
    }
    struct Node* slow = head;
    struct Node* fast = head;

    while(fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    fast = reverse(slow -> next);
    slow = head;


    while(fast != NULL) {
        if(slow -> data != fast -> data) {
            return false;
        }
        slow = slow -> next;
        fast = fast -> next;
    }

    return true;

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

    bool result = isPalindrome(head -> next);
    cout << result;
    return 0;
}