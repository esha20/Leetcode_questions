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
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt =1;
        ListNode* curr = head;
        ListNode* left = head;
        ListNode* right = head;
        
        while(curr){
            if(cnt<k) left= left->next;
            if(cnt>k) right = right->next;
            //above explaination means we start iterating once the left counter reaches its desired position
            //this also implies that curr is at k+1th node. that means curr is k nodes ahead of right pointer
            //once the left pointer reaches its position, right starts iterating.
            //so by the time curr reaches null, right reaches kth position from last
            
            
            cnt++;
            curr = curr->next;
        }
        swap(left->val,right->val);
        return head;
    }
};