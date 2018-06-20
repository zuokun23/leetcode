class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int , int> record;//键为int型，值为频次也为int型
        for(int i = 0 ; i < nums1.size() ; i++)
            record[nums1[i]]++;
        
        vector<int> resVector;
        for(int i = 0 ; i < nums2.size() ; i++)
            if(record[nums2[i]] > 0){
                record[nums2[i]]--;
                resVector.push_back(nums2[i]);
            }
        
        return resVector;
    }
};
