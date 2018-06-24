//思路：一种直接的方法是三重循环, 每次枚举一个值, 需要注意的重复的值, 也就是当在这一层使用了一个值之后, 
//继续在这一层选值的时候不可以再选这个, 也就是跳过. 
//另外初始的时候是无序的, 因此需要对数组先排序. 其时间复杂度是O(n^3).
//但是我们可以优化到O(n^2), 用双指针计数, 也就是先枚举一个值, 剩下的问题就退化成了2 sum的问题. 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
        if(nums.size() < 3)
            return vector<vector<int>>();
        
        vector<vector<int>> ret;
        sort(nums.begin() , nums.end());
        
        for(int i = 0 ; i < nums.size()-2 ; i++){
            
            int l = i+1,r = nums.size() - 1;
            while(l < r){//l==r时只有nums[i]和nums[l]两个元素，不能判断
                
                int val = nums[i] + nums[l] + nums[r];
                if(val == 0){
                    ret.push_back(vector<int>{nums[i] , nums[l] , nums[r]});
                    while(l + 1 < r && nums[l] == nums[l+1]) l++;
                    l++;
                    while(r - 1 > l && nums[r] == nums[r-1]) r--;
                    r--;
                }else if(val > 0)
                    r--;
                else
                    l++;
            }
            
            while(i + 1 < nums.size()-2 &&nums[i+1] ==nums[i]) i++;
        }
        
        return ret;
    }
};
