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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* temp = head->next;
        ListNode* curr = temp;
        head = temp;
        
        while(temp){
            if(temp->val == 0){
                curr->next = temp->next;
                temp = temp->next;
                curr=temp;
            }
            else{
                curr->val += temp->next->val;
                temp=temp->next;
            }
        }
        return head;
    }
};