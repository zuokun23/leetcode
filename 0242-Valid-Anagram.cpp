//1
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
            return false;
    
        unordered_map<char , int> record;
        for(int i = 0 ; i < s.size() ; i++)
            record[s[i]]++;

        for(int i = 0 ; i < t.size() ; i++)
            if(record[t[i]] > 0 ){
                record[t[i]]--;
            }else
                return false;

        return true;

    }
};

//2
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        if(s.length() != t.length())
            return 0;
        for(int i = 0; i < s.length(); i++) {
            a[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++) {
            a[t[i] -'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(a[i] != 0) {
                return 0;
            }
        }
        return 1;
    }
};
