//1
//即使输入的数为9*10^10，也会在第一次 while 降到3位数，第二次 while 降到2位数，不超过10次肯定能知道是否满足题目条件
//所以加了一个 cnt 计数器 在超过10次就跳出循环说明不满足题意
class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        while(n != 1) {
            cnt++;
            int temp = 0;
            while(n) {
                temp = temp + (n % 10) * (n % 10);
                n = n / 10;
            }
            n = temp;
            if(cnt == 10) {
                return false;
            }
        }
        return true;
    }
};

//2
//使用set/map来存储计算过的数，如果目前的数字已经计算过，表示会造成无穷循环。
class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> record;
        
        while(n != 1){
            
            if(record.find(n) != record.end())
                return false;
            record.insert(n);
            
            int temp = 0;
            while(n){
                temp += (n%10)*(n%10);
                n /= 10;
            }
            n = temp;
            
        }
        
        return true;
    }
};

//我的错误答案
class Solution {
public:
    bool isHappy(int n) {
        
        int cnt = 0;
        while(n != 1){
            int i = 10;
            int temp = 0;
            while(n % i != 0){//55%10 = 5没错，55%100 = 55得到各位和十位；
            
                temp += (n % i)*(n % i);
                i = i*10;
            }
            n = temp;
            cnt += 1;
            if(cnt >= 10)
                return false;
        }
        
        return true;
    }
};
