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
    int preorder(TreeNode* root, int &count, int low, int high){
        if(root==NULL)
            return 0;
        if(root->val >=low && root->val <= high){
            count+=root->val;
        }
        preorder(root->left, count , low, high);
        preorder(root->right, count, low, high);
        return count;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int count = 0;
        preorder(root , count,low,high); 
        return count ;
    }
};