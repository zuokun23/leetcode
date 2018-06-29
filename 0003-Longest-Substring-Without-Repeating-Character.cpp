//给定一个字符串，找出不含有重复字符的最长子串的长度。

//1滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0 , r = -1;//[l..r]为滑动窗口，窗口内不含有重复字符的子串，r=-1可以避免赋初值；也可以l=0,r=0,[l,r)表示窗口
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
//2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0)
            return 0;
        int l = 0 , r = 0;//[l..r]滑动窗口
        int res = 1;//初始窗口大小
        unordered_set<char> hash;
        hash.insert(s[0]);
        while(l < s.size()){
            
            if(r+1 < s.size() && hash.find(s[r+1]) == hash.end())
                hash.insert(s[++r]);
            else
                hash.erase(s[l++]);
            res = max(res , r - l + 1);
        }
        
        return res;
    }
};
