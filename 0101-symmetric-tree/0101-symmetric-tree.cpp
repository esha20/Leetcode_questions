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
    bool issym(TreeNode* p , TreeNode* q){
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL && q!=NULL)
            return false;
        if(p!=NULL&&q==NULL)
            return false;
        
        if(p->val == q->val){
            bool one=issym(p->left, q->right);
            bool two = issym(p->right, q->left);
            
            if(one && two)
                return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return issym(root->left, root->right);
    }
};