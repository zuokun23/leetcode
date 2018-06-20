class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        //set<int> record;
        //for(int i = 0 ; i < nums1.size() ; i++)
        //    record.insert(nums1[i]);
        set<int> record(nums1.begin() , nums1.end());
        
        set<int> resSet;
        for(int i = 0 ; i < nums2.size() ; i++)
            if( record.find(nums2[i]) != record.end() )
                resSet.insert(nums2[i]);
        
        //vector<int> resVector;
        //for(set<int>::iterator it = resSet.begin() ; it != resSet.end() ; it++){
            
        //    resVector.push_back(*it);
        //}
        //return resVector;
        
        return vector<int>(resSet.begin() , resSet.end());
    }
};
