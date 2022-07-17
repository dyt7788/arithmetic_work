#include<iostream>
using namespace std;

struct dt{
    int a,b,x,y;
} d[10001];
int main()
{
    int n,xn,yn,di=-1;//di最后结果输出 没有就是-1
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i].a>>d[i].b>>d[i].x>>d[i].y;
    }
    cin>> xn>>yn;
    for(int i=1;i<=n;i++)
    {
        if(xn>=d[i].a&&xn<=d[i].a+d[i].x&&yn>d[i].b&&yn<=d[i].b+d[i].y)
        {
            di=i;
        }//是不是在地毯区域范围内
    }
    cout<<di;
}