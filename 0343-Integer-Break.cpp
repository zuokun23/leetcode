//记忆化搜索
class Solution {
    
private:
    vector<int> memo;
public:
    int max3(int a , int b ,int c){
        return max(a , max(b,c));
    }
    int breakInt(int n){
        
        if(n == 1)
            return 1;
        if(memo[n] != -1)
            return memo[n];
        int res = -1;
        for(int  i = 1 ; i <= n - 1 ; i++)
            res = max3(res , i*(n-i) , i*breakInt(n-i));
        memo[n] = res;
        return res;
    }
    int integerBreak(int n) {
        memo = vector<int>(n+1 , -1);
        return breakInt(n);
    }
};
//动态规划
class Solution {

public:
    int max3(int a , int b ,int c){
        return max(a , max(b,c));
    }

    int integerBreak(int n) {
        vector<int> memo = vector<int>(n+1 , -1);
        
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            //求解memo[i]
            for(int j = 1 ; j <= i - 1 ; j++ ){//至少分割成两部分
                memo[i] = max3(memo[i] , j*(i-j) , j*memo[i-j]);
            }
        }
        return memo[n];
    }
};
