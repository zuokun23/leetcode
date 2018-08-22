class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     
        int m = grid.size() , n =grid[0].size();
        //1 状态为从(0,0)到某点最小路径和
        vector<vector<int>> dp = vector<vector<int>>(m , vector<int>(n , -1)) ;
        //2边界
        dp[0][0] = grid[0][0];
        for(int i = 1 ; i < m ; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i = 1 ; i < n ; i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        //3状态转移方程
        for(int i = 1 ; i < m ; i++)
            for(int j = 1 ; j < n ; j++)
                dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
        
        return dp[m-1][n-1];
    }
};
