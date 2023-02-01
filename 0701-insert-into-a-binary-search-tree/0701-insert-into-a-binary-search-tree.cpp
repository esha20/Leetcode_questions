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
    
    TreeNode* solve(TreeNode* &root, int val){
        if(root==NULL)
        {
            //null means the node where we want to insert has reached
            root = new TreeNode(val);
            return root;
        }
        
        else if(root->val > val)
            solve(root->left, val);
        
        else
            solve(root->right, val);
        
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};