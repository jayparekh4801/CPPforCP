#include <iostream>
#include <queue>

using namespace std ;

struct Node{
    int data;
    struct Node* left, *right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

void preorder(Node* root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << "\n";
    preorder(root -> left);
    preorder(root -> right);

}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
   
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << "\n";
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
   
    inorder(root -> left);
    cout << root -> data << "\n";
    inorder(root -> right);
    
}

void levelorder(Node* root) {

    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        struct Node* temp = q.front();
        cout << temp -> data << "\n";
        q.pop();
        if(temp -> left != NULL) {
            q.push(temp -> left);
        }

        if(temp -> right != NULL) {
            q.push(temp -> right);
        }

    }
}

void insertnode(Node* root, Node* node) {
    if(root == NULL) {
        return;
    }

    queue <Node*> q;
    q.push(root);

    while(!q.empty()) {

        struct Node* temp = q.front();
        q.pop();

        if(temp -> left == NULL) {
            temp -> left = node;
            break;
        }
        else {
            q.push(temp -> left);
        }

        if(temp -> right == NULL) {
            temp -> right = node;
            break;
        }

        else {
            q.push(temp -> right);
        }
    }
}

void deletedeepestnode(Node* root, Node* node) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        struct Node* temp = q.front();
        q.pop();

        if(temp -> left) {
            if(temp -> left == node) {
                temp -> left = NULL;
                delete(node);
                return;
            }
            else {
                q.push(temp -> left);
            }
        }

        if(temp -> right) {
            if(temp -> right == node) {
                temp -> right = NULL;
                delete(node);
                return;
            }
            else {
                q.push(temp -> right);
            }
        }
        

    }
}

void deletenode(Node* root, int key) {

    if(root == NULL) {
        return;
    }

    struct Node* temp;
    struct Node* key_node = NULL;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp -> data == key) {
            key_node = temp;
        }

        if(temp -> left) {
            q.push(temp -> left);
        }

        if(temp -> right) {
            q.push(temp -> right);
        }
    }

    key_node -> data = temp -> data;
    deletedeepestnode(root, temp);
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

    // preorder(root);
    // postorder(root);
    // inorder(root);

    struct Node* newNode = new Node(8);
    inorder(root);
    levelorder(root);
    deletenode(root, 1);
    levelorder(root);

    return 0;
}