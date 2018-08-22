//递归解，但超时
class Solution {

private:
    int tryRob(vector<int> &nums , int index){
        
        if(index >= nums.size())
            return 0;
        
        int res = 0;
        for(int i = index ; i < nums.size() ; i++){
            
            res = max(res , nums[i] + tryRob(nums , i+2));
        }
        return res;
    }
public:
    int rob(vector<int>& nums) {
        
        return tryRob(nums , 0 );
    }
};

//记忆化搜索
class Solution {

private:
    vector<int> memo;//memo[i]表示考虑抢劫[i..n-1]所能获得的最大收益
    
    int tryRob(vector<int> &nums , int index){
        
        if(index >= nums.size())
            return 0;
        if(memo[index] != -1)
             return memo[index];
        
        int res = 0;
        for(int i = index ; i < nums.size() ; i++){
            
            res = max(res , nums[i] + tryRob(nums , i+2));
        }
        memo[index] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size() , -1);
        return tryRob(nums , 0 );
    }
};
//动态规划
class Solution {

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //特判
        if(n == 0)
            return 0;
        //状态
        vector<int> memo = vector<int>(n , -1);//memo[i]表示考虑抢劫[i..n-1]所能获得的最大收益
        //边界
        memo[n-1] = nums[n-1];//陷阱:n == 0此处产生错误，加入特判
        
        //状态转移方程
        for(int i = n -2 ; i >= 0 ; i--){
            
            for(int j = i ; j <= n-1 ; j++)
                memo[i] = max(memo[i] , nums[j] + (j+2<n ? memo[j+2]:0));//j+2小心越界
        }
        
        return memo[0];
    }
};

//动态规划改变状态含义
class Solution {

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //特判
        if(n == 0)
            return 0;
        //状态
        vector<int> memo = vector<int>(n , -1);//memo[i]表示考虑抢劫[0..i]所能获得的最大收益
        //边界
        memo[0] = nums[0];
        
        //状态转移方程
        for(int i = 1 ; i < n ; i++){
            
            for(int j = 0 ; j <= i ; j++)//0..i先抢一家
                memo[i] = max(memo[i] , nums[j] + (j-2>=0 ? memo[j-2]:0));//j-2小心越界,从[0..j-2]的钱 + 在j处抢的钱
        }
        
        return memo[n-1];
    }
};
