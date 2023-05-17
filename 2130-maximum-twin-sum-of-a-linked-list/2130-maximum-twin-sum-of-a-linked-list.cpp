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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        vector<int> sumarr;
        int i=0;
        while(fast != NULL && fast->next != NULL){
            sumarr.push_back(slow->val);
            slow = slow->next;
            fast=fast->next->next;
            i++;
        }
        if(fast==NULL){
            while(slow){
                sumarr[i-1] += slow->val;
                i--;
                slow=slow->next;
            }
        }
        else{
            while(slow->next){
                sumarr[i-1] += slow->next->val;
                i--;
                slow=slow->next;
            }
        }
        int maxi = INT_MIN;
        for(int i=0;i<sumarr.size();i++){
            if(sumarr[i]>maxi)      maxi = sumarr[i];
        }
        return maxi;
    }
};