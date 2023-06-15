/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        int sum=root->val,curr=0, lvl =1, ans=1;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            auto topnode = q.front();
            q.pop();
            
            if(topnode==NULL){
                if(sum < curr)    {
                    ans = lvl; sum = curr;
                }
                curr =0;
                if(!q.empty())  {q.push(NULL);lvl++;}
            }
            else
            {
                curr+=topnode->val;
                if(topnode->left!=NULL){
                    q.push(topnode->left);
                }
                if(topnode->right!=NULL){
                    q.push(topnode->right);
                }
            }
        }
        return ans;
    }
};