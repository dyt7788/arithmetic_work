#include<iostream>
#include<vector>
#include<string>
using namespace std;
//整数划分一步一步划分
int spilt(int n,int m)
{
    if(n==1||m==1)
    {
        return 1;
    }
    else if(n<m) return spilt(n,n);
    else if(n==m) return 1+spilt(n,n-1);
    else return spilt(n,m-1)+spilt(n-m,m);
}
int main()
{
     cout<<spilt(6,6);
}