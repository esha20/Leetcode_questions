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
    void solve(TreeNode* root, int &count, int &ans, int level){
        if(root==NULL)
            return;
        if(count == level)
        {
            ans = root->val;
            count++;
        }
        solve(root->left,count,ans,level+1);
        solve(root->right, count,ans, level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int count=0, ans=0, level=0;
        solve(root, count, ans, level);
        return ans;
    }
};