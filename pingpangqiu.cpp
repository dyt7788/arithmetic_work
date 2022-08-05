#include<iostream>
#include<cmath>
using namespace std;
int flag=0;
int win[1001];

void race(int n)
{
     int a=0,b=0;
     for(int i=0;i<flag;i++)
     {
        if(win[i]=='W') a++;
        if(win[i]=='L') b++;
        if((a>=n||b>=n)&&abs(a-b)>=2)
        {
            cout<<a<<":"<<b<<endl;
            a=b=0;//进行清零
        }
     }

     cout<<a<<":"<<b<<endl;
}
int main()
{
    char str;
    while(cin>>str&&str!='E')
    {
        if(str=='W'||str=='L')
        {
            win[flag++]=str;
        }
    }
    race(11);
    cout<<endl;
    race(21);
    return 0;    
}