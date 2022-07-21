/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //we cant reach the previous node but we can instead copy the data of the next node to this current node and delete it.
        if(node==NULL)
            return;
        
        ListNode* nextnode=node->next;
        
        node->val=node->next->val;
        node->next=node->next->next;
        
        delete nextnode;
    }
};