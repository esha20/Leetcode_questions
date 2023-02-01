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
    int mini(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left){
            temp= temp->left;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root==NULL)
            return NULL;
        
        //found the node
        if(root->val == key){
            
            //0 child
            if(root->left == NULL && root->right == NULL){
                
                //simply delete the node and point the parent to null
                delete root;
                return NULL;
            }
            
            //1 child
            //left child
            if(root->left && !root->right){
                
                //return left child to its parent and make it the child of its parent
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            if(root->right && !root->left){
                
                //same as left child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            //2 child
            if(root->left && root->right){
                
                //either get the minimum from right subtree or the maximum from left subtree
                int minival = mini(root->right);
                
                //exchange the data of the node to be deleted with the min val
                root->val = minival;
                
                //now delete the node having min val in the right subtree with recursion
                root->right = deleteNode(root->right, minival);
                
                //dont change the tree above the current node so return root intact
                return root;
            }
        }
        
        else{
            
            //meaning the key is in left subtree
            if(root->val > key){
                
                //root->left will have the desired changes
                root->left=deleteNode(root->left, key);
                
                //but we dont want to alter the tree from current node and above so return the current node intact
                return root;
            }
            
            //key in right subtree
            else{
                root->right = deleteNode(root->right,key);
                
                return root;
            }
        }
        
        return root;
    }
};