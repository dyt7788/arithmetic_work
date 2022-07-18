//方格取数
//可以看成是两个人一起走
//可以把二维变成四维  
//使用动态规划来解决这个问题

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[12][12][12][12],a[12][12],n,x,y,z;
//x y 是位置 z是对应位置的值

int main()
{
    cin>>n>>x>>y>>z;
    while(x!=0||y!=0||z!=0)
    {
        a[x][y]=z;
        cin>>x>>y>>z;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=n;l++)//对每一步找到最大值
                {
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+a[i][j]+a[k][l];
                    //这里就包括两个人走的不同情况 两个都向下走
                    // 还是两个人一个向下一个向右,对前面位置进行一步一步类似于递归
                    //还有一种特殊情况时都走到了同一个位置 我们理解的是两个人实际上他是一个人
                    //所以在重合的地方只加一个
                    if(i==k&&l==j) f[i][j][k][l]-=a[i][j];
                }
    cout<<f[n][n][n][n];
    return 0;
}

