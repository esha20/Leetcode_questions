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
    int res(TreeNode* root, int& ans, int& mini) {
        if (root->left)
            res(root->left, ans, mini);
        if (ans > -1) 
            mini = min(mini ,root->val - ans);
        ans = root->val;
        if (root->right) 
            res(root->right, ans, mini);
    return mini;
}
int getMinimumDifference(TreeNode* root) {
    int mini = INT_MAX, ans = -1;
    return res(root, ans, mini);
    }
};