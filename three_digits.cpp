//数字1~9排列组合成三位数
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
bool a[10];
int v;
int main()
{
    for(int i=192;i<=327;i++)
    {
        memset(a,0,sizeof(a));
        v=0;
        //每一位标记为1 
        a[i%10]=a[i/10%10]=a[i/100]=a[i*2%10]=a[i*2/10%10]=a[i*2/100]=a[i*3%10]=a[i*3/10%10]=a[i*3/100]=1;
        for(int j=1;j<=9;j++)
            v+=a[j];
        if(v==9)
           cout<<i<<" "<<i*2<<" "<<i*3<<endl;
    }
    return 0;
}
