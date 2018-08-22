//超时，递归写法含重复子问题
class Solution {
public:
    int pathSum(int i,int j,vector<vector<int>>& triangle,int size){
        
        if(i == size-1)
            return triangle[i][j];
        return min(pathSum(i+1 , j , triangle , size) , pathSum(i+1 , j+1 , triangle , size)) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        return pathSum(0,0,triangle,triangle.size());
    }
};
//改进，记忆化搜索，依然超时
class Solution {

private:
    vector<vector<int>> dp;
public:
    int pathSum(int i,int j,vector<vector<int>>& triangle,int size){
        
        if(i == size-1)
            return triangle[i][j];
        if(dp[i+1][j] != -1 && dp[i+1][j+1] != -1)
		    return min(dp[i+1][j] , dp[i+1][j+1]) + triangle[i][j];
	    return min(pathSum(i+1 , j , triangle , size) , pathSum(i+1 , j+1 , triangle , size)) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp = vector<vector<int>>(triangle.size() , vector<int>(triangle.size() , -1)) ;
        return pathSum(0,0,triangle,triangle.size());
    }
};
//动态规划，自底向上
class Solution {

public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        //状态
        vector<vector<int>> dp = vector<vector<int>>(size , vector<int>(size , -1)) ;
        
        //边界
        for(int i = 0 ; i < size ; i++)
            dp[size - 1][i] = triangle[size-1][i];
        //状态转移方程
        for(int i = size - 2 ; i >= 0 ; i--)
            for(int j = 0 ; j <= i ; j++)
                dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + triangle[i][j];
        
        return dp[0][0];
    }
};
