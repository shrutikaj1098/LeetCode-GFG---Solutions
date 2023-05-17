//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
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
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* temp=head;
        int n=length(head);
        Node* prev=nullptr;
        if(k==n) return head;
        if(k>n) return head;
        while(k--)
        {
            prev=temp;
            temp=temp->next;
        }
        //cout<<prev->data;
        Node* restlist=temp;
        prev->next=nullptr;
        while(restlist->next)
        {
            restlist=restlist->next;
        }
        restlist->next=head;
        
        return temp;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends