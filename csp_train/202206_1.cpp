// csp 6月 第一题
#include<iostream>
#include<cstdio>

#include<cmath>
using namespace std;
double a[10001];
int main()
{
   int n;
   cin>>n;
   float avg,d;
   avg=0;
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
    avg=avg+a[i];
   }
   avg=avg/n;
   d=0;
   for(int i=0;i<n;i++)
   {
     d=d+pow(a[i]-avg,2);
   }
   d=d/n;
   for(int i=0;i<n;i++)
   {
    printf("%f\n",(a[i]-avg)/pow(d,0.5));
    
   }
}