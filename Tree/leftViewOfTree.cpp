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

void leftView(Node *root)
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
        struct Node *temp = q.front();
        if (temp)
        {
            cout << temp->data;

            while (q.front() != NULL)
            {
                if (temp -> left)
                {
                    q.push(temp -> left);
                }

                if (temp -> right)
                {
                    q.push(temp -> right);
                }

                q.pop();
                temp = q.front();
            }
            q.push(NULL);
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

    leftView(root);

    return 0;
}