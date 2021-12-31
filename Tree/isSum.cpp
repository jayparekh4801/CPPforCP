#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left, right;
    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
}

bool isLeaf(Node* root) {
    if(root == NULL) {
        return false;
    }

    if(root -> left == NULL && root -> right == NULL) {
        return true;
    }
    return false;
}

bool isSumTree(Node* root) {
    if(root == NULL || isLeaf(root)) {
        return true;
    }

    int ls;
    int rs;

    if(isSumTree(root -> left) && isSumTree(root -> right)) {
        if(root -> left == NULL) {
            ls = 0;
        }

        else if(isLeaf(root -> left)) {
            ls = root -> left -> data;
        }

        else {
            ls = 2 * root -> left -> data;
        }

        if(root -> right == NULL) {
            rs = 0;
        }

        else if(isLeaf(root -> right)) {
            rs = root -> right -> data;
        }

        else {
            rs = 2 * root -> right -> data;
        }

        return (root -> data == ls + rs);
    }

    return false;
}

int main() {

    return 0;
}