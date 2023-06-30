//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(struct Node* head)
    {
        Node* prev=nullptr;
        while(head)
        {
            Node* forw=head->next;
            head->next=prev;
            prev=head;
            head=forw;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        Node* first=new Node(-1);
        Node* second=new Node(-1);
        Node* temp=odd, *f=first, *s=second;
        bool flag=true;
        while(temp)
        {
            if(flag)
            {
                first->next=new Node(temp->data);
                first=first->next;
                flag=false;
            }
            else
            {
                second->next=new Node(temp->data);
                second=second->next;
                flag=true;
            }
            temp=temp->next;
        }
        temp=odd;
        s=s->next;
        s=reverse(s);
        first->next=s;
        f=f->next;
        while(temp)
        {
            temp->data=f->data;
            temp=temp->next;
            f=f->next;
        }
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends