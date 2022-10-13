//最大收益问题 投资
//使用动态规划的算法
#include<iostream>
using namespace std;
const int M=5;
const int N=6;//二维数组的空间大小
int maxprofit(int dp[M][N],int f[M][N],int money,int number)
{
    for(int i=1;i<=number;i++)
    {
        for(int j=0;j<=money;j++)
        {
            dp[i][j]=0;
            for(int k=0;k<=j;k++)
            {
                if(dp[i][j]<f[i][k]+dp[i-1][j-k])
                    dp[i][j]=f[i][k]+dp[i-1][j-k];
            }
        }
    }
    return dp[number][money];
}
int main()
{
    int dp[M][N]={0};
    int f[M][N]={
        0,0,0,0,0,0,
        0,11,12,13,14,15,
        0,0,5,10,15,20,
        0,2,10,30,32,40,
        0,20,21,22,23,24
    };
    cout<<"max profit:"<<maxprofit(dp,f,5,4)<<endl;
}