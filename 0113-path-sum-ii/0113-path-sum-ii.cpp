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
    // int j=0;
    // vector<int> solve(TreeNode* root, int target, vector<int> paths,vector<vector<int>> &ans){
    //     if (root==NULL)
    //         return paths;
    //     if(root->left ==NULL && root->right==NULL){
    //        if((target-=root->val) ==0) {
    //             paths.push_back(root->val);
    //            for(auto i :paths){
    //             ans[j].push_back(i);
    //            }
    //            j++;
    //            return paths;
    //        }
    //        else
    //             return paths;
    //     }
    //     paths.push_back(root->val);
    //     solve(root->left, target-root->val,paths,ans);
    //     solve(root->right, target-root->val,paths,ans);
    //     return paths;
    // }
    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     vector<vector<int>> ans;
    //     vector<int> paths;
    //     solve(root, targetSum, paths,ans);
    //     return ans;
    // }
    void solve(TreeNode* root, int target, vector<int> paths, vector<vector<int>> &ans){
        if (root==NULL)
            return;
        
        if(root->left ==NULL && root->right==NULL){
            target-=root->val;
            if(target==0)
            {
            paths.push_back(root->val);
            ans.push_back(paths);
            }
            return;
        }
        paths.push_back(root->val);
        solve(root->left, target-root->val,paths,ans);
        solve(root->right, target-root->val,paths,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> paths;
        solve(root,targetSum,paths,ans);
        return ans;
    }
};