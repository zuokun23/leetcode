//27：给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = -1;//[0,j]保存!=val元素，i用来遍历数组
        
        for(;i < nums.size() ; i++){
            if(nums[i] != val)
                nums[++j] = nums[i];
        }
        return j+1;
    }
};

//2
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = 0;//[0,j）保存!=val元素，i用来遍历数组
        
        for(;i < nums.size() ; i++){
            if(nums[i] != val)
                nums[j++] = nums[i];
        }
        return j;
    }
};
//3
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = 0;//[0,j）
        
        for(;i < nums.size() ; i++){
            if(nums[i] != val){
                if(i != j)//增加此判断来处理特殊数组：全部元素!=val时，不过耗时反而增加...
                    nums[j++] = nums[i];
                else
                    j++;
            }
        }
        return j;
    }
};
//4
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = 0;
        
        for(;i < nums.size() ; i++){
            if(nums[i] != val){
                if(i != j)
                    swap(nums[j++],nums[i]);//最后结果中[j,nums.size())元素值均=val，本题没做这个要求
                else
                    j++;
            }
        }
        return j;
    }
};
