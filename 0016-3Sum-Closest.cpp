//虽然能跑出结果，但有bug
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int size = nums.size();
        int ret = INT_MAX/2;//为了使第一次ret-target>val-target
        
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i <= size-3 ; i++){
            int l = i+1 , r = size-1;
            while(l < r){
                
                int val = nums[i] + nums[l] + nums[r];
                if(abs(val - target) < abs(ret - target)){
                    ret = val;
                }
                if(val > target)
                    r--;
                else
                    l++;
            }
        }
        
        return ret;
    }
};
//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int size = nums.size();
        int ret;
        
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i <= size-3 ; i++){
            int l = i+1 , r = size-1;
            while(l < r){
                int val = nums[i] + nums[l] + nums[r];
                if(i == 0 && l == 1 && r == size-1)//针对ret初始值进行了优化
                    ret = val;
                if(abs(val - target) < abs(ret - target)){
                    ret = val;
                }
                if(val > target)
                    r--;
                else
                    l++;
            }
        }
        
        return ret;
    }
};
