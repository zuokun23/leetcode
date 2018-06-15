//给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
//函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

//无解？保证有解
//有重复解？输出任意解

//1暴力法，运行超时 O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ret;
        for(int i = 0; i < numbers.size() ; i++){
            for(int j = i+1; i < numbers.size(); j++){
                
                if(numbers[i] + numbers[j] == target){
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    return ret;
                }
                    
            }
        }
        
    }
};
//2对撞指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)    {
        int l = 0, r = numbers.size() -1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                int ret[2] = {l+1 , r+1};
                return vector<int>(ret , ret+2);
            }
            else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        
    }
};
//3二分搜索
