//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    vector<int>v;
    Node* temp=head;
    while(temp)
    {
        v.push_back(temp->data);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    int ans=0;
    int n=v.size();
    int i=0;
    while(i<n-2)
    {
        int s=i+1,e=n-1;
        while(s<e)
        {
            int target=v[i]+v[s]+v[e];
            if(target==x)
            {
                ans++;
                s++;e--;
            }
            else if(target>x)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        i++;
    }
    return ans;
} 