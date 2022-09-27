//模拟正则表达表达式
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool isMatch(string s,string p)
    {
        int m=s.size();
        int n=p.size();
        auto matches=[&](int i,int j)//在内部定义一个类似于函数的东西
        {
            if(i==0){return false;}
            if(p[j-1]=='.')
            {
                return true;
            }
            return s[i-1]==p[j-1];
        };
        vector<vector<int>>f(m+1,vector<int>(n+1));
        f[0][0]=true;//边界
        for(int i=0;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[j-1]=='*'){
                    f[i][j]|=f[i][j-2];
                    if(matches(i,j-1)){
                        f[i][j]|=f[i-1][j];
                    }
                }
                else{
                    if(matches(i,j)){
                        f[i][j]|=f[i-1][j-1];
                    }
                }
            }
        }
        return f[m][n];
    }
};