//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//1和2实现细节不一样，1更容易记忆，2效率稍微高点
//1
class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        if(sz == 0)
            return true;
        
        int i = 0,j = sz - 1;
        while(true){
            
            while(i <= sz-1 && !isValid(s[i])) i++;//
            while(j >= 0 && !isValid(s[j])) j--;//
            if(i >= j) //只进行三次边界判断，更容易理解，且终止条件在while内，[i,i]含一个字符串时为回文,条件判断不能为==
                return true;      
            if(s[i] == s[j] || s[i] >= 'A' && s[i] <= 'Z' && s[j] == s[i] + 32 || s[j] >= 'A' && s[j] <= 'Z' && s[i] == s[j] + 32){
                i++;
                j--;
            }
            else
                return false;
        }
    }
    bool isValid( char t){
        if(t>='a' && t<='z' || t>='A' && t<='Z' || t>='0' && t<= '9')
            return true;
        else
            return false;
    }
};
//2
class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        if(sz == 0)
            return true;
        
        int i = 0,j = sz - 1;
        while(i < j){//进行四次边界判断，可提前终止循环
            while(i < j && !isValid(s[i])) i++;//
            while(i < j && !isValid(s[j])) j--;//
            if(i == j) //
                return true;
            
            if(s[i] == s[j] || s[i] >= 'A' && s[i] <= 'Z' && s[j] == s[i] + 32 || s[j] >= 'A' && s[j] <= 'Z' && s[i] == s[j] + 32){
                i++;j--;
            }
            else
                return false;    
        }
        return true;//此处容易忽略，这种算法有两个return true的出口。
    }
    
    bool isValid( char t){
        if(t>='a' && t<='z' || t>='A' && t<='Z' || t>='0' && t<= '9')
            return true;
        else
            return false;
    }
};
