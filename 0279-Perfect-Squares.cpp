class Solution {
public:
    bool isSquareNum(int n){
        int t = (int)sqrt(1.0*n);
        if(t*t == n)
            return true;
        return false;
    }
    int numSquares(int n) {
    
        //状态
        vector<int> dp(n+1 , n+1);//表示由n+1个square数组成
        //边界
        for(int i = 1 ; i*i <= n ; i++)
            dp[i*i] = 1;
        //状态转移方程
        for(int i = 2 ; i <= n ; i++){
            if(isSquareNum(i) == true)
                continue;
            for(int j = 1 ; j*j < i ; j++){
                dp[i] = min(dp[i] , dp[i-j*j] + 1);//1 == dp[j*j]
            }
        }
        
        return dp[n];
    }
};
