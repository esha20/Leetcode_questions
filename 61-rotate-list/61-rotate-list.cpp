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
    ListNode* rotateRight(ListNode* &head, int k) {
        //if the ll is empty return null
        if(head==NULL)
            return NULL;
        
        //if the ll has only one node, it does not need to be rotated.
        if(head->next==NULL){
            return head;
        }
        
        ListNode* temp=head;
        int len=0;
        while(temp)
        {
            //to find out the length of the ll
            temp=temp->next;
            len++;
        }
        
        if(len<k)
        {
        //if the no. of rotations needed is more than length then,
        //we only have to rotate the number that comes as reminder when k is div by no of nodes.
        //since if there are 3 nodes and k=4 then the result is same as k=1 because after 3                 rotations, the ll returns to its original state
        k=k%len;
        }
        
        if(k>0)
        {
        ListNode* curr = head;
        ListNode* tail = head;
        
        //rotate it once
        //reach the last node with tail pointer and the last second node with curr pointer
        while(tail->next!=NULL)
        {
            curr=tail;
            tail=tail->next;
        }
        curr->next=NULL;
        tail->next=head;
        head=tail;
        tail=curr;
        }
        if(k>1)
        {
        //decrement before recurrsion so that it rotates k-1 times since we rotated it                       manually once.
        k--;
        rotateRight(head,k);
        }
            return head;
    }
};