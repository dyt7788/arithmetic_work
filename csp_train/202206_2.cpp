//藏宝图
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
//在一个大矩阵中找一个小矩阵
// bool A[10001][10001]={false,false}; //大地图
int n,L,S;
struct point
{
    int x;
    int y;
};

point lmap[1005];//绿化结构体数组
int wlmap[55][55];//挖出的S+1 S+1维的数组
int smap[55][55];
int sum=0;//最后结果 宝藏的个数
int set(point p,point xlmap[],int xwlmap[][55])
{
    for(int i=0;i<=S;i++)
    {
        for(int j=0;j<=S;j++)
        {
            xwlmap[i][j]=0;//存储矩阵初始化
        }
    }
    int x=p.x;
    int y=p.y;
    for(int i=0;i<n;i++)
    {
        int xi=xlmap[i].x-x;
        int yi=xlmap[i].y-y;
        if(xi>=0&&xi<S&&yi>=0&&yi<=S)
        {
            xwlmap[xi][yi]=1;//每一个点是否可能是矩阵的起始点
        }
    }
    return 0;
}
bool compare(int xwlmap[][55],int xsmap[][55])
{
    //是否重合起点
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<S;j++)
        {
            if(xsmap[i][j]!=xwlmap[i][j])
            return false;
        }
        
    }
    return true;
}
int main(){
    cin>>n>>L>>S;
    for(int i=0;i<n;i++)
    {   
        cin>>lmap[i].x>>lmap[i].y;
    }

    for(int i=S;i>=0;i--)
    {
        for(int j=0;j<=S;j++)
        {
            cin>>smap[i][j];
         }
    }
    for(int i=0;i<n;i++)
    {
        if(lmap[i].x+S<=L&&lmap[i].y+S<=L)
        {
            set(lmap[i],lmap,wlmap);
            if(compare(wlmap,smap))
            {
                sum++;
            }
        }
    }
    cout<<sum-1;
    return 0;
}