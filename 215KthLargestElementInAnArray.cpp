//215：在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5

//1递归
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //快速排序的思想
     
        return quickSort(nums , 0 , nums.size()-1 ,nums.size() - k);
    }      
    
    int quickSort(vector<int>& nums ,int l ,int r ,int t ){
        
        int p = partition(nums ,l ,r );
        if(t == p)
            return nums[p];
        else if(t < p)
            quickSort(nums , l ,p-1 , t);
        else
            quickSort(nums, p+1 , r ,t);
    }

    int partition(vector<int>& nums ,int l ,int r){
    
        int v = nums[l];
        int i = l+1,j = l;//[l+1,j]保存<v的元素
        for(; i <= r; i++)
            if(nums[i] < v)
                swap(nums[i],nums[++j]);
        swap(nums[l], nums[j]);
    
        return j;
    }
};

//2非递归
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //快速排序的思想
        k = nums.size() - k;
        int l = 0 , r = nums.size()-1;
        while(true){
            int p = partition(nums , l , r);
            if(p == k)
                return nums[k];
            else if(p < k)
                l = p+1;
            else
                r = p-1;
        }
    }      
    
    int partition(vector<int>& nums ,int l ,int r){
    
        int v = nums[l];
        int i = l+1,j = l;//[l+1,j]保存<v的元素
        for(; i <= r; i++)
            if(nums[i] < v)
                swap(nums[i],nums[++j]);
        swap(nums[l], nums[j]);
    
        return j;
    }
};
