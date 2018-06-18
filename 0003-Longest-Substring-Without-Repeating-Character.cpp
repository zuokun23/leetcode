//给定一个字符串，找出不含有重复字符的最长子串的长度。

//1滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0 , r = -1;
        int res = 0;
        
        while(l < s.size()){
            
            if(r + 1 < s.size() && freq[s[r+1]] == 0)
                freq[s[++r]]++;
            else
                freq[s[l++]]--;
            
            res = max(res , r - l + 1);
        }
        
        return res;
    }
};
