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
    vector<int> ans;
    //declaring vector to store the traversed array
    
    vector<int> preorderTraversal(TreeNode* root) {
        //if root is null meaning the node is not having any data so we dont have to traverse or store.
        if(root==NULL)
            return ans;
        
        
        //preorder method is node left and then right. meaning we store , move left and then move right.
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
        return ans;
    }
};