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
    //declaring a vector to store the traversed array
    vector<int> postorderTraversal(TreeNode* root) {
        //if there is no node, i.e. no data to traverse and store , so return the vector.
        if(root == NULL)
            return ans;
        
        //postorder method is left right and then node i.r. we traverse to left , right and then print.
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        
        return ans;
    }
};