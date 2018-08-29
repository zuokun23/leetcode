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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //终止条件
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL )
            return false;
        
        //递归式--明确函数定义--对应两棵树是否相同--从自底向上角度看，先判断子树是否同再看自身
        if(isSameTree(p->left , q->left) && isSameTree(p->right , q->right))
            if(p->val == q->val)
                return true;
        return false;
    }
};
