//给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
//字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
//
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        if(s.size() < p.size())
            return res;

        assert(p.size() > 0);

        vector<int> freq_p(26, 0);
        for(char c: p)
            freq_p[c - 'a'] += 1;

        vector<int> freq_s(26, 0);
        int l = 0, r = -1; // Sliding window: s[l, r]
        while(r + 1 < s.size()){
            r ++;
            freq_s[s[r] - 'a'] ++;
            if(r - l + 1 > p.size())
                freq_s[s[l++] - 'a'] --;

            if(r - l + 1 == p.size() && same(freq_s, freq_p))
                res.push_back(l);
        }

        return res;
    }

private:
    bool same(const vector<int>& freq_s, const vector<int>& freq_p){
        for(int i = 0 ; i < 26; i ++)
            if(freq_s[i] != freq_p[i])
                return false;
        return true;
    }
};
