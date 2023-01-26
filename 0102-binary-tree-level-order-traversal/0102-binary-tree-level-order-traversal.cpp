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
    void solve(TreeNode* root, vector<int> level, vector<vector<int>> &ans){
        queue<TreeNode*> q;
        if(root==NULL)
            return;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* frontnode = q.front();
            q.pop();

            if(frontnode==NULL){
                ans.push_back(level);
                level.clear();
                if(!q.empty()){

                    q.push(NULL);
                }
            }
            else{
                level.push_back(frontnode->val);
                if(frontnode->left)     q.push(frontnode->left);
                if(frontnode->right)    q.push(frontnode->right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int>level;
        solve(root,level,ans);
        return ans;
    }
};