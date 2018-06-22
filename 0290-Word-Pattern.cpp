//1
class Solution {
public:
    bool wordPattern(string pattern, string str) {

        unordered_map<char , string> record1;
        unordered_map<string , char> record2;//双向映射

        //split the str
        vector<string> strVec;
        int i = 0 , j = -1;//[i , j]表示一个非空单词
        while(j + 1 < str.size()){
    
            while(j + 1 < str.size() && str[j+1] == ' ') j++;
            if(j + 1 >= str.size())
                break;
            i = ++j;
            while(j + 1 < str.size() && str[j+1] != ' ') j++;
            //j+1越界或j+1为空时，[i..j]均可以表示非空单词
            strVec.push_back(str.substr(i,j - i + 1));
        }

        int k = 0;
        auto it = strVec.begin();
        for(; it != strVec.end() && k < pattern.size() ; it++,k++){
            if(record1.find(pattern[k]) == record1.end() && record2.find(*it) == record2.end()) {//find里是key，双向都找不到，保证一一对应
                record1.insert(make_pair(pattern[k], *it));//可以用insert；或=
                record2.insert(make_pair( *it , pattern[k]));
            }
            else if(record1.find(pattern[k]) == record1.end() && record2.find(*it) != record2.end())
                return false;
            else if(record1.find(pattern[k]) != record1.end() && record2.find(*it) == record2.end())
                return false;
            else
                if( record1.find(pattern[k])->second != *it)//find返回迭代器，传统c中字符串直接比较比较的时两个地址
                    return false;

        }
        if(k == pattern.size() && it == strVec.end())
            return true;
        else
            return false;

    }
};

//2
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> mymap;
        unordered_map<string,char> m;
        stringstream ss(str);
        string s;
        for(char i:pattern)
        {
            if(!(ss>>s)) return false;
            if(mymap.find(i)!=mymap.end())
            {
                if(mymap[i].compare(s)) return false;
            }
            else
            {
                mymap[i]=s;
            }
            if(m.find(s)!=m.end())
            {
                if(m[s]!=i) return false;
            }
            else
                m[s]=i;
        
        }
        if(ss>>s) return false;
        else return true;
    }
};

//3
class Solution {  
public:  
    bool wordPattern(string pattern, string str) {  
        str += " ";  
        int i = 0, j = 0, len1 = pattern.size(), len2=str.size();  
        unordered_map<char, string> hash1;  
        unordered_map<string, char> hash2;  
        while(i < len1 && j < len2)  
        {  
            int pos = str.find(' ', j);  
            string s = str.substr(j, pos-j);  
            if(hash1.count(pattern[i]) && hash1[pattern[i]]!=s) return false;  
            if(hash2.count(s) && hash2[s]!= pattern[i]) return false;  
            hash1[pattern[i]] = s, hash2[s] = pattern[i];  
            i++, j = pos+1;  
        }  
        return i==len1 && j ==len2;  
    }  
};
