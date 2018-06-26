class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int> , vector<string>> hash;//key为异构词的特征：每个字母的频次，value为一个存储着所有异构词的vector,注意此处不能用unordered_map
        for(auto it = strs.begin() ; it != strs.end() ; it++){

            vector<int> tmp(26, 0);
            for (char i : *it)
                tmp[i - 'a']++;

            if(hash.find(tmp) == hash.end()){//此处不能用hash[key]，因为key不为int类型，此处==表示没找到
                vector<string> a;
                a.push_back(*it);
                hash.insert(make_pair(tmp , a));
            } else{
                hash.find(tmp)->second.push_back(*it);
            }
        }

        vector<vector<string>> ret;
        for(auto it = hash.begin() ; it != hash.end() ; it++)//将hash表中second导入ret
            ret.push_back(it->second);

        return ret;
    }
};
//用string类型作为key，来简化操作，
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string , vector<string>> hash;//key为string类型
        string tmp;
        for(auto i : strs){    
            tmp = i;
            sort(tmp.begin() , tmp.end());//sort后异构单词一致
            hash[tmp].push_back(i);    
        }

        vector<vector<string>> ret;
        for(auto it = hash.begin() ; it != hash.end() ; it++)//将hash表中second导入ret
            ret.push_back(it->second);

        return ret;
    }
};
