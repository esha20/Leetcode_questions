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
    TreeNode* solve(TreeNode* root, int val, TreeNode* &ans){
        if (root==NULL)
            return NULL;
        if(root->val == val)
            ans = root;
        else if(root->val > val)
            solve(root->left, val,ans);
        else
            solve(root->right,val,ans);
        
        return ans;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = NULL;
        root = solve(root,val, ans);
        return root;
    }
};