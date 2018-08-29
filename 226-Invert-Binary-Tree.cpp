//1
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
     
        if(root == NULL)
            return NULL;
        
        invertTree(root->left);
        swap(root->left , root->right);
        invertTree(root->left);//注意此时left和right已经交换，这步对left操作实际是对right操作
        
        return root;
    }
};
//2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
     
        if(root == NULL)
            return NULL;
        
        swap(root->left , root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
//3
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
     
        if(root == NULL)
            return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left , root->right);
                
        return root;
    }
};
