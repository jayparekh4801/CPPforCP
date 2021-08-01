#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left, *right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return (1 + max(height(root -> left), height(root -> right)));
}

int diameterOfTree(Node* root) {

    if(root == NULL) {
        return 0;
    }
    int ldiam = diameterOfTree(root -> left);
    int rdiam = diameterOfTree(root -> right);

    int lheight = height(root -> left);
    int rheight = height(root -> right);

    return max(max(ldiam, rdiam), lheight + rheight + 1);
}

int main() {

    struct Node* root = new Node(1);
    struct Node* first = new Node(2);
    struct Node* second = new Node(3);
    struct Node* third = new Node(4);
    struct Node* fourth = new Node(5);
    struct Node* fifth = new Node(6);
    struct Node* sixth = new Node(7);
    struct Node* seventh = new Node(8);

    root -> left = first;
    root -> right = second;
    first -> left = third;
    first -> right = fourth;
    second -> left = fifth;
    second -> right = sixth;
    sixth -> left = seventh;

    int ans = diameterOfTree(root);
    cout << ans;

    return 0;
}