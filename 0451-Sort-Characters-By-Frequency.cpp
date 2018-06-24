//1利用map自动给键排序的性质
class Solution {
public:
    string frequencySort(string s) {

    map<char , int> r1;
    multimap<int , char> r2;

    for(char i : s)//给r1赋值
        r1[i]++;

    auto it1 = r1.begin();//给r2赋值
    for(;it1 != r1.end() ; it1++)
        r2.insert(make_pair(it1->second ,it1->first));
        //r2[it1->second] = it1->first;

    string ret;
    auto it2 = r2.rbegin();
    for(; it2 != r2.rend() ; it2++){
        for(int i = 0 ; i < it2->first ; i++)
            ret += it2->second;
    }

    return ret;
}
};
//2利用优先队列（最大堆）
class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> q;
        unordered_map<char, int> m;
        for (char c : s) 
            m[c]++;
        for(auto a:m)
            q.push({a.second, a.first});
        while(!q.empty())
        {
            auto t = q.top();
            q.pop();
            res.append(t.first, t.second);//字符与频次
        }
        return res;
    }
};

//3最常见思想：利用vector,然后进行排序
bool vSort(const pair<int , char>& a , const pair<int , char>&b){
        return a.first > b.first;
}

class Solution {
    
public:
    string frequencySort(string s) {

        map<char , int> m;
        for(char i : s){
            m[i]++;
        }
        
        vector<pair< int , char>> v;
        for(auto i : m)
            v.push_back(make_pair(i.second , i.first));
        sort(v.begin() , v.end() , vSort);//排序
        
        string ret;
        for(auto i : v){
            
            ret.append(i.first , i.second);
        }
        
        return ret;
    }
    
};
