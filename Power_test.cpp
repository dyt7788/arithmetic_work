#include<iostream>
using namespace std;

//每一个十进制数都可以用二进制表示

//使用二进制加递归的方法

int n;
void find(int x)
{
    if(n!=0)
    {
        int a=1,b=0;
        cout<<"2";
        while(x>=a)
        {
            ++b;
            a*=2;
        }
        --b;//多加了一个
        if(b==0||b==2)
          cout<<"("<<b<<")";
        if(b>=3)
        {
            cout<<"(";
            find(b);
            cout<<")";
        }
        x-=a/2;
        if(x)
        {
            cout<<"+";
            find(x);
        }
    }
}
int main()
{
     cin>>n;
     find(n);
     return 0;
}
