//暴力解法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        assert(s > 0);
        vector<int> sums(nums.size() + 1 , 0);//难点
        for(int i = 1 ; i <= nums.size() ; i++)
            sums[i] = sums[i-1] + nums[i-1];
        
        int res = nums.size() + 1;//难点
        for(int l=0 ; l<nums.size() ; l++)
            for(int r=l ; r<nums.size() ; r++)
                if(sums[r+1] - sums[l] >= s)
                    res = min(res , r-l+1);
        
        if(res == nums.size() + 1)
            return 0;
        return res;
        
    }
};
//滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        int l = 0 , r = 0;//[l,r]//为滑动窗口
        int sum = nums[0];//sum为滑动窗口的值
        int ret = nums.size() + 1;
        while(r < nums.size() ){
            
            if(sum >= s){
                ret = min(ret , r-l+1);
                sum -= nums[l++];
            }else{
                if(r+1 < nums.size())
                    sum += nums[++r];
                else
                    break;
            }
        }
        
        if(ret == nums.size() + 1)
            return 0;
        return ret;
    }
};
//二分搜索
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert(s > 0);

        // sums[i]存放nums[0...i-1]的和
        vector<int> sums(nums.size() + 1, 0);
        for(int i = 1 ; i <= nums.size() ; i ++)
            sums[i] = sums[i-1] + nums[i-1];

        int res = nums.size() + 1;
        for(int l = 0 ; l < (int)nums.size() - 1 ; l ++){

            auto r_bound = lower_bound(sums.begin(), sums.end(), sums[l] + s);
            if(r_bound != sums.end()){
                int r = r_bound - sums.begin();
                res = min(res, r - l);
            }
        }

        if(res == nums.size() + 1)
            return 0;

        return res;
    }
};
