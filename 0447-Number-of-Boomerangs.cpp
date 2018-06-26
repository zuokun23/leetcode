
//暴力解O(n^3),遍历所有i,j,k 0
//i:0->n-1;j:0->n-1且不等于i;k:0->n-1且不等于i和j

//查找表
// 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs/description/
// 时间复杂度: O(n^2)
// 空间复杂度: O(n)
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {

        int res = 0;
        for( int i = 0 ; i < points.size() ; i ++ ){

            // record中存储 点i 到所有其他点的距离出现的频次
            unordered_map<int, int> record;
            for(int j = 0 ; j < points.size() ; j ++)
                if(j != i)
                    // 计算距离时不进行开根运算, 以保证精度
                    record[dis(points[i], points[j])] += 1;

            for(unordered_map<int, int>::iterator iter = record.begin() ; iter != record.end() ; iter ++)
                res += (iter->second) * (iter->second - 1);
        }
        return res;
    }

private:
    int dis(const pair<int,int> &pa, const pair<int,int> &pb){
    //注意两点的距离可能超出INT_MAX，此时有定义要long long 类型，由题意没超出不用考虑INT_MAX = 2147483647
        return (pa.first - pb.first) * (pa.first - pb.first) +
               (pa.second - pb.second) * (pa.second - pb.second);
    }
};
