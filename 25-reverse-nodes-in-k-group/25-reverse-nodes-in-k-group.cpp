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
    bool len_rev(ListNode* head, int k){
        //find the length of ll first
        ListNode* temp=head;
        int len=0;
        
        while(temp)
        {
            temp=temp->next;
            len++;
        }
        
        if(len>=k)
            return true;
        else
            return false;
        }
    
    
    ListNode* reverseKGroup(ListNode* &head, int k) {
        
        //base case
        if(!len_rev(head,k))
        {
            return head;
        }
        
        //reverse one group
        ListNode* curr= head;
        ListNode* prev =NULL;
        ListNode* nextnode=NULL;
        
        int flag =0;
        while(flag < k && curr != NULL)
        {
        nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
        flag++;
        }
        
        
        //recurrsively solve the rest of the list
        //here the nextnode is the new head for the next set of reversal
        
        if(nextnode)
        head->next=reverseKGroup(nextnode,k);
        
        return prev;
    }
};