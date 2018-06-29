//查找表
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> hash;
        for(int i = 0 ; i < nums.size() ; i++){
            if(hash.find(nums[i]) == hash.end())
                hash.insert(nums[i]);
            else
                return true;
        }
        
        return false;
    }
};
//滑动窗口
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        
        sort(nums.begin() , nums.end());
        int i = 0 , j = 1;//[0..i]为非重复元素
        for(; j < nums.size() ; j++)
            if(nums[j] != nums[i])
                i++;
            else
                return true;
        
        return false;
    }
};
