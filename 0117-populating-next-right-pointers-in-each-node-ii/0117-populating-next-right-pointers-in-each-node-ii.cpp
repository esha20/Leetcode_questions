/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //read question carefully, it says in the first test case that the output is in level order. 
    //so we use the level order approach. even if the hint was not give, we can see that the nodes are traversed        horizontally level wise so use the level order traversal
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        
        queue <Node*> q ;
        //using the separator logic. we use null as separator to use after every level.
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            //store the frontnode of the queue
            Node* frontnode = q.front();
            q.pop();
            
            //if the frontnode is null, check for the next queue. 
            //if queue is not empty, agle level k liye null dal do
            if(frontnode==NULL){
               // q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                //agar null nahi hai abhi ka frontnode toh uska left aur right queue mei add kar do.
                frontnode->next=q.front();
                if(frontnode->left)      q.push(frontnode->left);
                if(frontnode->right)     q.push(frontnode->right);
            }
        }
        return root;
    }
};