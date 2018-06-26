class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
        int size = nums.size();
        if(size < 4)
            return vector<vector<int>>();
    
        sort(nums.begin() , nums.end());
        //使其退化为3sum问题
        //vector<vector<int>> retVec;
        set<vector<int>> retSet;//使用set去重复
        for(int i = 0 ; i <= size-4; i++){//如 0 0 0 0 ,i最多取到倒数第四个,这种边界问题非常重要
            int t1 = target - nums[i];
            for(int j = i+1 ; j <= size -3 ; j++){
                int t2 = t1 - nums[j];
                int l = j+1, r = size -1;
    
                while(l < r){//[l..r] l!=r
                    if(nums[l] + nums[r] == t2){
                        retSet.insert(vector<int>{ nums[i] , nums[j] , nums[l] , nums[r] });
                        l++;
                        r--;
                    }else if(nums[l] + nums[r] > t2)
                        r--;
                    else
                        l++;
                }
            }
        }
        //auto it = retSet.begin();
        //for( ; it != retSet.end() ; it++){
        //    retVec.push_back(*it);
        //}

        return vector<vector<int>>(retSet.begin() , retSet.end());
    }
};
