//给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。
class Solution {
public:
    string minWindow(string s, string t) {
        
        string ret;
        if(s.size() < t.size())
            return ret;
        int min = s.size() + 1;
        
        int freq_s[128] = {0};
        int freq_t[128] = {0};
        for(char c : t)
            freq_t[c]++;
        
        int l = 0 , r = -1;//r = -1可以不用对freq_s手动赋初值 
        while(l < s.size()){
            
            if(hasCommon(freq_s , freq_t)){//如果[l..r]包含T，l++
                
                if(r - l + 1 < min){
                    min = r - l + 1;
                    //strncpy(ret , s+l , r-l+1); 
                    ret = "";
                    for(int i = l ; i <= r ; i++){
                        ret += s[i];
                    }
                }
                freq_s[s[l++]]--;
            }else if(r + 1 < s.size()){//如果不包含 且 l+1不越界，r++
                
                freq_s[s[++r]]++;
            }
            else//否则 break
                break;

        }
        
        return ret;
    }
private:
    bool hasCommon(int freq_s[] , int freq_t[]){
        
        for(int i = 0 ; i <= 127 ; i++)
            if(freq_t[i] > freq_s[i])//注意这里是> 
                return false;
        
        return true;
    }
};

//2
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        for (const auto &c : t) ++mp[c];
        size_t cnt = t.size(), begin = 0, end = 0, d = ULONG_MAX, head = 0;

        while (end < s.size()) {
            if (mp[s[end++]]-- > 0) --cnt;
            while (cnt == 0) {
                if (end - begin < d) d = end - (head = begin);
                if (mp[s[begin++]]++ == 0) ++cnt;
            }
        }

        return d == ULONG_MAX ? "" : s.substr(head, d);
    }
};
