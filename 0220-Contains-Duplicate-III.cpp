class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set<long long> record;
        for(int  i = 0 ; i < nums.size() ; i++){
            
            auto it = record.lower_bound((long long)nums[i] - (long long)t);
            if(it != record.end() && *it <= (long long)nums[i] + (long long)t)
                return true;
            
            record.insert((long long)nums[i]);
            if(record.size() == k+1)
                record.erase(nums[i-k]);
        }
        return false;
    }
};
