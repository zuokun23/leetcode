//80:给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int i = 1 , j = 0;//[0,j]是安全区
        int flag = true;//记录出现次数
        for(;i < nums.size() ; i++ ){
            
            if(nums[i] != nums[j] ){
                nums[++j] = nums[i] ;
                flag = true;
            }
            else if(flag == true){
                nums[++j] = nums[i];
                flag = false;
            }
            //else 什么都不做   
        }
        
        return j+1;
        
    }
};
//2可以扩展到最多出现n次
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int i = 1 , j = 0;//[0,j]是安全区
        int times = 1;//记录出现次数
        for(;i < nums.size() ; i++ ){
            
            if(nums[i] == nums[j] ){
                if(times < 2){
                    times += 1;
                    nums[++j] = nums[i]; 
                }
            }
            else{
                nums[++j] = nums[i];
                times = 1;
            }
              
        }
        
        return j+1;
        
    }
};
//3 针对特殊用例进行优化
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 2)
            return sz;
        int i = 1 , j = 0;//[0,j]是安全区
        int times = 1;//记录出现次数
        for(;i < sz ; i++ ){
            
            if(nums[i] == nums[j] ){
                if(times < 2){
                    times += 1;
                    nums[++j] = nums[i]; 
                }
            }
            else{
                nums[++j] = nums[i];
                times = 1;
            }
              
        }
        
        return j+1;
        
    }
};
