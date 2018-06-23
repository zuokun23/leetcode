class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int size1 = s.size() , size2 = t.size();
        if(size1 != size2)
            return false;
        
        unordered_map<char , char> hash1;//一一对应
        unordered_map<char , char> hash2;
    
        int j = 0;
        for(char i : s){
            
            if(!hash1.count(i))//没找到
                hash1[i] = t[j];
            else//找到
                if(hash1[i] !=  t[j])
                    return false;
            
            if(!hash2.count(t[j]))
                hash2[t[j]] = i;
            else
                if(hash2[t[j]] != i)
                    return false;
            j++;
        }
        
        return true;
    }
};
