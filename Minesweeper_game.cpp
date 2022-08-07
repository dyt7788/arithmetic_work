#include<iostream>
using namespace std;
bool a[105][105];
int main()
{
    int n,m;
    cin>>n>>m;
    char str;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>str;
            if(str=='*')
            a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            cout<<"*";
            else{
                cout<<a[i+1][j+1]+a[i+1][j-1]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i-1][j+1]+a[i-1][j]+a[i-1][j-1];
            }
        }
        cout<<endl;
    }
    return 0;
}