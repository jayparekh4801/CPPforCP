#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left, right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }   
};

void topViewOfTree(Node* root) {
    if(root == NULL) {
        
    }
}


int main() {
    struct Node* root = new Node(1);
    struct Node* second = new Node(2);
    struct Node* third = new Node(3);
    struct Node* fourth = new Node(4);
    struct Node* fifth = new Node(5);
    struct Node* sixth = new Node(6);
    struct Node* seventh = new Node(7);

    root -> left = second;
    root -> right = third;
    second -> left = fourth;
    second -> right = fifth;
    third -> left = sixth;
    third -> right = seventh;



    root -> left = 
    root -> 
    return 0;
}