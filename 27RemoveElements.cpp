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
