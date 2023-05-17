//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* solve(Node* first,Node* second)
    {
        Node* ans=new Node(-1);
        Node* left=first,*right=second,*start=ans;
        while(left && right)
        {
            if(left->data<right->data)
            {
                ans->next=left;
                left=left->next;
                ans=ans->next;
            }
            else
            {
                ans->next=right;
                right=right->next;
                ans=ans->next;
            }
            
        }
             while(left)
            {
                ans->next=left;
                left=left->next;
                ans=ans->next;
            }
            while(right)
            {
                 ans->next=right;
                right=right->next;
                ans=ans->next;
            }
            return start->next;
        
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           for(int i=1;i<K;i++)
           {
               arr[i]=solve(arr[i-1],arr[i]);
           }
           return arr[K-1];
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends