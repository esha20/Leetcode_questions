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
    ListNode *detectCycle(ListNode *head) {
        
        //return null if the ll is empty
        if(head==NULL)
            return NULL;
        
        //a map to store the bool value to mark the visited nodes
        map<ListNode*,bool> visited;
        
        //to keep a track of the node we just visited
        ListNode* temp=head;
        
        while(temp)
        {
            //if the node is already visited,meaning the loop starts from here
            if(visited[temp]==true)
            {
                return temp;
            }
            //mark the node after visiting
            visited[temp]=true;
            temp=temp->next;
        }
        
        //if no node is visited twice, meaning no cycle.
        return NULL;
    }
};