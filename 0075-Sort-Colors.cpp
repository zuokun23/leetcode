//75:给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

//1一个直观的解决方案是使用计数排序的两趟扫描算法。
//首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz =nums.size();
        if(sz == 0)
            return;
        
        int count[3] = {0};//存放0,1,2存放的频率
        for(int i = 0; i < sz ; i++){
            assert(nums[i] >= 0 && nums[i] <=2 );
            count[nums[i]]++;
        }
        
        int index = 0;
        for(int i = 0 ; i < count[0] ; i++){
            nums[index++] = 0;
        }
        for(int i = 0 ; i < count[1] ; i++){
            nums[index++] = 1;
        }
        for(int i = 0 ; i < count[2] ; i++){
            nums[index++] = 2;
        }
    
    }
};
//2
class Solution {
public:
    void sortColors(vector<int>& nums) {//三路快排的思想
        int sz = nums.size();
        if(sz == 0)
            return;
        int zero = -1, two = sz,i = 0;//[0,zero]保存0,[two,sz-1]保存2,[zero+1,i-1]保存1,[i,two-1]为未遍历元素
        while(i < two){//i==two时无可遍历的元素
            
            if(nums[i] == 0){
                swap(nums[++zero],nums[i]);
                i++;
            }
            else if(nums[i] == 1)
                i++;
            else{//==2时
                assert(nums[i] == 2);
                swap(nums[--two],nums[i]);
            }    
        }
    }
};
