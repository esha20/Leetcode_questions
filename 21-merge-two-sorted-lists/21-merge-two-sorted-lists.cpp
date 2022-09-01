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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* new_list=new ListNode();
        ListNode* temp= new_list;
        
        //while both the lists are not empty
        while(list1 && list2)
        {
            //put the value of the smaller value node in the new list
            if(list1->val <= list2->val)
            {
                temp->next= list1;
                list1=list1->next;
            }
            else
            {
                temp->next= list2;
                list2=list2->next;
            }
            //increment the list
            temp=temp->next;
        }
        
        //if any of the two lists remain when one of the two reaches null, copy the rest of the elements in the new list
        if(list1)
        {
            temp->next=list1;
        }
        if(list2)
        {
            temp->next=list2;
        }
        return new_list->next;

    }
};