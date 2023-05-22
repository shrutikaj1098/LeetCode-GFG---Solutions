/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getlength(ListNode* head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int n=getlength(head);
        if(n==1)
        {
            
            return nullptr;
        }
        int k=n/2-1;
        ListNode* temp=head;
        while(k--)
        {
            temp=temp->next;
        }
        // cout<<temp->val;
        if(temp->next->next)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp->next=nullptr;
        }
        return head;
    }
};