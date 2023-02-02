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
    int solve(TreeNode* &root, int &sum){
        if(root==NULL)
            return sum;
        
        else if(root->right == NULL && root->left==NULL)
        {
            root->val += sum;
            return root->val;
        }
        
        sum = solve(root->right, sum);
        
        root->val+=sum;
        sum = root->val;
        
        sum = solve(root->left,sum);
        
        return sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum =0;
        solve(root, sum);
        return root;
    }
};