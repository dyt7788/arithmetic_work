#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a=0,b=0,c=0;
    cin>>a>>b>>c;
    int flag=0;
    for(int i=10;i<100;i++)
    {
        if(i%3==a&&i%5==b&&i%7==c)
        {
            cout<<i<<endl;
            flag=1;
         }
    }
   if(flag==0)
   {
    cout<<"No answer"<<endl;
   }
}