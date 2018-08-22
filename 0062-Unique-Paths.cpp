//直接用动态规划，有兴趣可以试试递归（会超时），记忆化搜索（更加容易理解，且不超时）
class Solution {
public:
    int uniquePaths(int m, int n) {
        //状态
        vector<vector<int>> dp = vector<vector<int>>(m , vector<int>(n , -1));
        
        //边界
        for(int i = 0 ; i < m ; i++)
            dp[i][0] = 1;
        for(int i = 1 ; i < n ; i++)
            dp[0][i] = 1;
        //状态转移方程
        for(int i = 1 ; i < m ; i++ )
            for(int j = 1 ; j < n ;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};
