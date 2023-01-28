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
    vector<int> ans;    //declaring vector to store the solution
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;     //node is null means no data so just return
        
        //the method is left node right i.e. first traverse to the left nodes and then print the node then omve to right
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        inorder(root);
        return ans;
    }
};