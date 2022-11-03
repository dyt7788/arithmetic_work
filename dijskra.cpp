#include <cstdio>
#include <cstdlib>
#include<cstring>
#include<iostream>
const int MAXN=1000,INF=0x3f3f3f3f;
using namespace std;
int n,m;
int graph[MAXN][MAXN];
bool check[MAXN];
int dis[MAXN];
void dijkstra(){
    
    int temp_dis=INF,temp_i;//dis表示距离 i下标
    for(int i=1;i<=n;i++)
    {
        if(dis[i]<m&&!check[i])
        {
            temp_dis=dis[i];
            temp_i=i;
        }
    }
    check[temp_i]=true;
    for(int i=1;i<=n;i++)
    {
        if(dis[temp_i]+graph[temp_i][i]<dis[temp_i])
            dis[i]=dis[temp_i]+graph[temp_i][i];//对于每一个节点的距离都要更新
    }

}
int main()
{
    cin>>n>>m;//n表示顶点数 m表示边数
    memset(graph,88,sizeof(graph));
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[a][b]=w;//无向图数组的初始化时双向的
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                graph[i][j]=0;
    memset(dis,88,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        dis[i]=graph[1][i];//第一行
    }
    check[1]=true;
    
    for(int i=1;i<n;i++)
    {
        dijkstra();
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}