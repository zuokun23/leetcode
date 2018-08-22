class Solution {
public:
    bool isLegal(string s){
        //特判
        if(s[0] == '0')
            return false;//"101"
	    int t = stoi(s);
	    if(t >= 1 && t <= 26)
		    return true;
	    else
		    return false;
    }

    int numDecodings(string s) {
	    int n = s.size();
	    if(n == 0)
		    return 0;
            
	    //状态
	    vector<int> dp(s.size() , 0);//初始每位均是0种
	    //边界
	    if(s[0] == '0')
		    return 0;
        if(n == 1)
            return 1;
	    dp[0] = 1;
	    if(isLegal(s.substr(1 , 1)) == true)
		    if(isLegal(s.substr(0 , 2)) == false)
			    dp[1] = 1;//"33"
	    	else
		    	dp[1] = 2;//"23"
	    else
		    if(isLegal(s.substr(0 , 2)) == false)
			    return 0;//"30"
		    else
			    dp[1] = 1;//"20"

    	//状态转移方程
	    for(int i = 2 ; i < n ; i++){
    
    		if(isLegal(s.substr(i , 1)) == true)
	    		if(isLegal(s.substr(i-1 , 2)) == false)
		    		dp[i] = dp[i-1];//"33"
			    else
				    dp[i] = dp[i-1] + dp[i-2];//"23"
		    else
			    if(isLegal(s.substr(i - 1, 2)) == false)
				    return 0;//"30"
			    else
				    dp[i] = dp[i-2];//"20"

	    }   

    	return dp[n-1];
    }
};
