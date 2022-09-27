#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[100010]={0};
    // a[0]=1;
    int result=0;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        if(a[y]==0&&y!=0)
        {
            result++;
        }
        a[x]=1;//对应位置赋值为1
    }
    cout<<result;
    return 0;
}
