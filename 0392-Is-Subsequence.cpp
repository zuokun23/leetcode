class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i = 0 , j = 0;
        while(i < s.size() && j < t.size()){
            
            if(t[j] != s[i])
                j++;
            else{
                j++;
                i++;
            }
        }
        
        if(i == s.size())
            return true;
        return false;
        
    }
};
