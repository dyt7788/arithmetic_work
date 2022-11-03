#include<iostream>
using namespace std;

const int MAXN=1000,INF=0x3f3f3f3f;

int group[MAXN][MAXN],dist[MAXN],n,m;
int result;
int check[MAXN];

void prime()
{
    dist[1]=0;//第一个节点加入
    check[1]=1;
    for(int i=2;i<=n;i++) 
        dist[i]=min(dist[i],group[1][i]);
    for(int i=2;i<=n;i++)//对于每一个节点
    {
        int temp=INF;//边的大小
        int temp_i=-1;//距离最近加入 数组中 用于记录下标
        for(int j=2;j<=n;j++)
        {
            if(!check[j]&&dist[j]<temp)
            {
                temp=dist[j];
                temp_i=j;//找到最小边以及对应的顶点
            }
        }
        if(temp_i==-1) //图是空的
        {
            result=INF;
            return ;
        }
        check[temp_i]=1;
        result+=dist[i];
        for(int j = 2 ; j <= n ; j++)
            dist[j] = min(dist[j],group[temp_i][j]);
            //更新dist[j] 
    }

}
int main()
{
    cin>>n>>m;//n表示顶点数 m表示边数
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            group[i][j]=INF;//初始化
        }
        dist[i]=INF;//初始化数组
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        group[a][b]=group[b][a]=w;//无向图数组的初始化时双向的
    }
    prime();
    if(result==INF)
    {
        cout<<"null"<<endl;
    }
    else
    {
        cout<<result<<endl;
    }
    return 0;
}
