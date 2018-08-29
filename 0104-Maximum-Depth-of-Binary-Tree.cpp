/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 虽然递归都是自顶向下
 但方法1时有自底向上的思想的（如用递归和记忆化搜索解决动态规划问题时），因为时由叶子的高度1，一级一级升高，到根结点的最大高度
 方法2是自顶向下的思想的，利用tmp不断更新最大值max（想到dijkstra中对路径的保存利用dfs解决相关问题）；
 */
 //方法1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
          return 0;
          
        return max(maxDepth(root->left) , maxDepth(root->right)) + 1;
    }
};

//方法2
class Solution {
    
private:
    int maxLen = 0 ,tmp = 0;
    
    void maxDep(TreeNode* root){
  
        if(root == NULL)
            return;
        //前序+后序遍历思想
        tmp++;
        maxLen = max(tmp , maxLen);
        maxDep(root->left);
        maxDep(root->right);
        tmp--;
    }
public:
    int maxDepth(TreeNode* root) {
        
        maxDep(root);
        return maxLen;
    }
};
