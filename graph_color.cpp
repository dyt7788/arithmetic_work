#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int N=100;
int arr[N][N];//无向图邻接矩阵
int color[N];//记录下每一个节点的颜色
int result=0,n,m;//result着色方案数 n节点数 m颜色数

bool check(int i)
{
    for(int j=1;j<=i;j++)
    {
        if(arr[i][j]==1&&color[j]==color[i])//节点相联颜色相同返回false
         return false;
    }
    return true;
}
void display()
{
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<" ";
    }
}
void flush_back(int i)//每一层
{
    if(i>n)
    {
        // display();
        result++;
        return ;
    }
    else{
        for(int k=1;k<=m;k++)
        {
            color[i]=k;
            if(check(i)==1)//满足条件下一步
            {
                flush_back(i+1);
            }
            color[i]=0;//回溯
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
        flush_back(1);
    cout<<result;
}