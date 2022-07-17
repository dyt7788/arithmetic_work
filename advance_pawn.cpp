#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long;
using namespace std;
//马周围的位置
const int fx[]={0,-2,-1,1,2,2,1,-1,-2};
const int fy[]={0,1,2,2,1,-1,-2,-2,-1};

int bx,by,mx,my;//终点 以及 马的位置

long long f[40][40];  //最后结果存放在终点位置 终点位置的数组里面的值就是对应的答案

bool s[40][40];

int main()
{
    scanf("%d%d%d%d",&bx,&by,&mx,&my);
    bx+=2;by+=2;mx+=2;my+=2;
    f[2][1]=1;
    s[mx][my]=1;
    for(int i=1;i<=8;i++)
        s[mx+fx[i]][my+fy[i]]=1;//对应不能走的位置
    for(int i=2;i<=bx;i++)
    for(int j=2;j<=by;j++)
    {
        if(s[i][j]) continue;//是1也就是不能走的位置就直接跳过
        f[i][j]=f[i-1][j]+f[i][j-1]; //第i，j个位置来的方向只能是ll当前位置的左边以及上边两个方向。
    }
    printf("%lld\n",f[bx][by]);//为什么要加ll
    return 0;
}


