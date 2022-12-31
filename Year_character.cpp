#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//1 对应A AA对应27 就是以26为循环
int main()
{
    int n=2019;
    while(n!=0)//因为是倒序所以最后结果是BYQ
    {
        char temp='A'+n%26-1;
        cout<<temp;
        n=n/26;
    }
}
