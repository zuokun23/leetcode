//26：给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)//防止容器类型为空，没加会报错
            return 0;
        int i = 1,j = 0;//[0,j]是安全区
        
        for(;i < nums.size() ; i++ )
            if(nums[i] != nums[j])
                nums[++j] = nums[i];//由于不需要考虑数组中超出新长度后面的元素，不用swap()
        
        return j+1;
    }
};
