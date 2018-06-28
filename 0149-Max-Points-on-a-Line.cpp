/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


class Solution {
public:
    int maxPoints(vector<Point>& points) {

        if(points.size() < 3)
            return points.size();
        
        int maxRet = 0;//注意初值
        map<vector<int> , int> r;//每个斜率对应的点的索引，set是为了去重
        for(int i = 0 ; i < points.size() ; i++){//以一个点为中心点，斜率相同的在同一直线上
        
            r.clear();
            int same = 1;//注意初值
            for(int j = 0 ; j < points.size() ; j++){
                if(j == i)//
                    continue;
                else if(points[i].x == points[j].x && points[i].y == points[j].y){//值重复
                    same += 1;
                }else{
                    if(points[i].x == points[j].x){
                        vector<int> tmp{1 , 0};//就是斜率无穷
                        r[tmp]++;

                    }else{
                        //保存分式的形式
                        int tmp_y = points[i].y - points[j].y;
                        int tmp_x =points[i].x- points[j].x;
                        int tmp_gcd = gcd(tmp_x , tmp_y);
                        tmp_x /= tmp_gcd;
                        tmp_y /= tmp_gcd;
                            
                        vector<int> tmp_l = {tmp_y , tmp_x};
                        r[tmp_l]++;
                    }
                }
            }
            
            //找最大值
            maxRet = max( same , maxRet);//防止[[1,1],[1,1],[1,1]]这个测试用例
            for(auto it = r.begin() ; it != r.end() ; it++){
                
                maxRet = max(it->second + same , maxRet);
            }

        }
        return maxRet;
        
    }
private:
    int gcd(int a , int b){
        if(b == 0)
            return a;
        else
            return gcd(b , a%b);
    }
};
