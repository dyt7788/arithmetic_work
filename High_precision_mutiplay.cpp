#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string a1,b1;
int a[10001],b[10001];
int c[10001];
int main()
{
    cin>>a1>>b1;
    int a_size=a1.size();
    int b_size=b1.size();
    for(int i=1;i<=a_size;i++) a[i]=a1[a_size-i]-'0';
    for(int i=1;i<=b_size;i++) b[i]=b1[b_size-i]-'0';

    for(int i=1;i<=b_size;i++)
        for(int j=1;j<=a_size;j++)
        {
            c[i+j-1]+=a[j]*b[i];
        }
    for(int i=1;i<a_size+b_size;i++)
    {
        if(c[i]>9)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    int len=a_size+b_size;
    while(c[len]==0&&len>1)len--;
    for(int i=len;i>=1;i--)cout<<c[i];
    return 0;
}