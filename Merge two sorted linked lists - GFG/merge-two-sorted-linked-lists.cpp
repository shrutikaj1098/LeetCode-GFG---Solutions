//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
int length(Node* head)
{
    int count=0;
    while(head)
    {
        head=head->next;
        count++;
    }
    return count;
}
Node* solve(Node* curr, Node* remain)
{
    Node* prev=nullptr;
    Node* start=curr;
    while(curr && remain)
    {
        if(curr->data>remain->data)
        {
            if(prev==nullptr)
            {
                Node* new1=new Node(remain->data);
                new1->next=curr;
                //prev->next=new1;
                prev=new1;
                start=new1;
                //curr=curr->next;
                remain=remain->next;
            
            }
            else
            {
                Node* new1=new Node(remain->data);
                new1->next=curr;
                prev->next=new1;
                prev=new1;
                //curr=curr->next;
                remain=remain->next;
            }
        }
        else
        {
            prev=curr;
             curr=curr->next;
        }
        
    }
    if(remain)
        {
            prev->next=remain;
        }
    return start;
}
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    int len1=length(head1);
    int len2=length(head2);
    if(len1>len2)
    {
        Node* curr=head1;
        return solve(curr, head2);
    }
    else
    {
        Node* curr=head2;
        return solve(curr, head1);
    }
    
    
}  