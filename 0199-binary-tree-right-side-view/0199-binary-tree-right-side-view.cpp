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
    //declaring a vector to store the right view ele of the tree
    vector<int> ans;
    
    void solve(TreeNode* root,  int level){
        
        //if root is null then there is no data to traverse
        if(root == NULL)
            return;
        
        //if this node is the first node of the level form the right,we push this into the vector.
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        
        //traverse the entire tree, but right node first since we want the right view of the tree.
        solve(root->right,level+1);
        solve(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};