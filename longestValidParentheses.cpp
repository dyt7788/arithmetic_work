#include<bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s){
    int size=s.length();
    vector<int> dp(size,0);
    int maxval=0;
    for(int i=1;i<size;i++)
    {
        if(s[i]==')'){
            if(s[i-1]=='('){
                dp[i]=2;
                if(i-2>=0){
                    dp[i]=dp[i]+dp[i-2];
                }
            }else if(dp[i-1]>0){//说明前面已经匹配
                if((i-dp[i-1]-1)>=0&&s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2;
                    if((i-dp[i-1]-2)>=0)
                    {
                        dp[i]=dp[i-dp[i-1]-2];
                    }
                }
            }

        }
        maxval=max(maxval,dp[i]);
    }
    return maxval;
}