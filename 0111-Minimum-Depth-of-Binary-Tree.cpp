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
public:
    int minDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        if(root->left && root->right)
            return min(minDepth(root->left) , minDepth(root->right)) + 1;
        else
            return max(minDepth(root->left) , minDepth(root->right)) + 1;
    }
};
//注意下面这种情况
//      0
//      /
//      1    
