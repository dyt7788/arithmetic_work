/*
小渊和小轩是好朋友也是同班同学，他们在一起总有谈不完的话题。
一次素质拓展活动中，班上同学安排坐成一个 mm 行 nn 列的矩阵，
而小渊和小轩被安排在矩阵对角线的两端，因此，他们就无法直接
交谈了。幸运的是，他们可以通过传纸条来进行交流。
纸条要经由许多同学传到对方手里，小渊坐在矩阵的左上角，
坐标 (1,1)(1,1)，小轩坐在矩阵的右下角，坐标 (m,n)(m,n)。
从小渊传到小轩的纸条只可以向下或者向右传递，从小轩传给小渊
的纸条只可以向上或者向左传递。
*/
//很类似于上一道题目 使用动态归划  用空间换时间
#include<iostream>
#define maxn 55
using namespace std;
int f[maxn][maxn][maxn][maxn],a[maxn][maxn];
int n,m;
int max_ele(int a,int b, int c,int d)
{
    if(b>a)
        a=b;
    if(c>a)
        a=c;
    if(d>a)
        a=d;
    return a;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=j+1;l<=m;l++)
                {
                    f[i][j][k][l]=max_ele(f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1],f[i-1][j][k-1][l])+a[i][j]+a[k][l];
                }
    cout << f[n][m-1][n-1][m] <<endl;
    return 0;   
}