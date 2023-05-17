//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
     node* reverse1(node* head)
    {
        node* prev=nullptr,*curr=head;
        while(curr)
        {
            node* forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    int getlength(node* head)
    {
        int count=0;
        while(head)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head ||!head->next) return head;
        node* curr=head;
        node* dum=head;
         int c=getlength(head);
        if(k>c) k=c;;
        int count=1;
        node*prev=nullptr;
        while(count!=k)
        {
            //prev=curr;
            curr=curr->next;
            count++;
        }
        if(curr==nullptr) return head;
       node* restlist=curr->next;
       
       curr->next=nullptr;
       node* y=reverse1(dum);
       curr=y;
       while(curr->next!=nullptr)
       {
           curr=curr->next;
           //cout<<y->data;
       }
       curr->next=restlist;
       head->next=reverse(restlist,k);
       
        return prev?head:y;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends