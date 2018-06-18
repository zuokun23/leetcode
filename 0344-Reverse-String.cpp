//请编写一个函数，其功能是将输入的字符串反转过来。

class Solution {
public:
    string reverseString(string s) {
        if(s.empty())
            return s;
        //对撞指针
        int i = 0,j = s.size() - 1;
        while(i < j){
            swap(s[i] , s[j]);
            i++;
            j--;
        }
        return s;
    }
};
