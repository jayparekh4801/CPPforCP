#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node * merge(Node* A, Node * B) {
    Node* l1;
    Node* l2;
    Node* result;
    
    if(A -> data <= B -> data) {
        l1 = A;
        l2 = B;
    }
    else {
        l1 = B;
        l2 = A;
    }
    
    result = l1;
    
    while(l1 != NULL && l2 != NULL) {
        Node* temp = NULL;
        while(l1 != NULL && l1 -> data <= l2 -> data) {
            temp = l1;
            l1 = l1 -> bottom;
        }
        temp -> bottom = l2;
        Node* temp2 = l1;
        l1 = l2;
        l2 = temp2;
    }
    
    return result;
}


Node *flatten(Node *root)
{
    // Your code here
    if(root -> next == NULL) {
       return root;
    }
   
    Node* l2 = flatten(root -> next);
    Node* result = merge(root, l2);
    result -> next = NULL;
    return result;
   
}