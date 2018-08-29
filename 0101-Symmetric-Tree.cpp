/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
private:
    bool func(TreeNode* left , TreeNode* right){
        
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        
        if(func(left->left , right->right)&&func(left->right , right->left))
            if(left->val == right->val)
                return true;
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
        return func(root->left , root->right);
    }
};
