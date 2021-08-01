#include <iostream>

using namespace std ;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

Node* findLCANode(Node* root, int n1, int n2) {
    if(root == NULL) {
        return root;
    }

    if(root -> data == n1 || root -> data == n2) {
        return root;
    }

    struct Node* left_lca = findLCANode(root -> left, n1, n2);
    struct Node* right_lca = findLCANode(root -> right, n1, n2);

    if(left_lca && right_lca) {
        return root;
    }

    if(left_lca) {
        return left_lca;
    }
    else {
        return right_lca;
    }
}

int main() {

    struct Node* root = new Node(1);
    struct Node* first = new Node(2);
    struct Node* second = new Node(3);
    struct Node* third = new Node(4);
    struct Node* fourth = new Node(5);
    struct Node* fifth = new Node(6);
    struct Node* sixth = new Node(7);

    root -> left = first;
    root -> right = second;
    first -> left = third;
    first -> right = fourth;
    second -> left = fifth;
    second -> right = sixth;

    struct Node* ans = findLCANode(root, 4, 5);
    cout << ans -> data;

    return 0;
}