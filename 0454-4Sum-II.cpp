//利用hash表存储 A+B C+D的所有可能分别放入表中
// 时间复杂度: O(n^2)
// 空间复杂度: O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        //O(n^2)
        unordered_map<int , int> hash1;
        for(int i = 0 ; i < A.size() ; i++)
            for(int j = 0 ; j < B.size() ; j++)
                hash1[A[i] + B[j]]++;
        
        //O(n^2)
        unordered_map<int , int> hash2;
        for(int i = 0; i < C.size() ; i++)
            for(int j = 0 ; j < D.size() ; j++)
                hash2[C[i] + D[j]] ++;
        
        int res = 0;
        //O(n)
        for(auto it = hash1.begin() ; it != hash1.end() ; it++)
            if(hash2.find(-it->first) != hash2.end())
                res += it->second * hash2.find(-it->first)->second;
        
        return res;
    }
};

//利用hash表存储C+D的所有可能，然后遍历A和B
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        unordered_map<int , int> record;
        for(int i = 0; i < C.size() ; i++)
            for(int j = 0 ; j < D.size() ; j++)
                record[C[i] + D[j]] ++;
        
        int res = 0;
        for(int i = 0 ; i < A.size() ; i++)
            for(int j = 0 ; j < B.size() ; j++)
                if(record.find(0 - A[i] - B[j]) != record.end())
                    res += record[0 - A[i] - B[j]];
        
        return res;
    }
};
