//滑动窗口+查找表
//时间复杂度O(n)
//空间复杂度O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(nums.size() <= 1)
            return false;
        if(k <= 0 )
            return false;
        
        unordered_set<int> hash;
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(hash.find(nums[i]) != hash.end())
                return true;
            
            hash.insert(nums[i]);
            // 保持record中最多有k个元素
            // 因为在下一次循环中会添加一个新元素,使得总共考虑k+1个元素
            if(hash.size() == k+1)
                hash.erase(nums[i - k]);
        }
        
        return false;
    }
};
//算法超时，但思想是对的，O(n^2)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(nums.size() < 2)
            return false;
        if(k < 1)
            return false;
        
        for(int i = 0 ; i < nums.size()-1 ; i++){
            int j = i+1;
            while(j < nums.size() && j <= i + k && nums[j] != nums[i] ) j++;
            if(j > i+k)
                continue;
            if(j < nums.size() && nums[j] == nums[i])//找到
                return true;
        }
        
        return false;
    }
};
