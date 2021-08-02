#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void rightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        struct Node *temp;
        if (q.front() != NULL)
        {
            while (q.front() != NULL)
            {
                temp = q.front();

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }

                q.pop();
            }
            q.push(NULL);
            cout << temp->data;
        }
        q.pop();
    }
}

int main()
{
    struct Node *root = new Node(1);
    struct Node *first = new Node(2);
    struct Node *second = new Node(3);
    struct Node *third = new Node(4);
    struct Node *fourth = new Node(5);
    struct Node *fifth = new Node(6);
    struct Node *sixth = new Node(7);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    second->left = fifth;
    second->right = sixth;

    rightView(root);
    return 0;
}