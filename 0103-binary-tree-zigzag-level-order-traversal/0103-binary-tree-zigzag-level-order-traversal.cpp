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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root==NULL)      return ans;
        bool flag = true;
        
        queue <TreeNode*> q;
        q.push(root);
        // q.push(NULL);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> res;
            
            while(size--){
            TreeNode* frontnode = q.front();
            q.pop();
            res.push_back(frontnode->val);
            if(frontnode->left)    { 
                q.push(frontnode->left);  
            }
            if(frontnode->right) {
                q.push(frontnode->right);
            }
            }
            
            if(flag == false){
               reverse(res.begin(), res.end());
               flag = true;
               ans.push_back(res);
            }
            else{
                ans.push_back(res);
                flag = false;
            }
            res.clear();
        }
        return ans;
    }
};