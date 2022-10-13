#include<iostream>
#include<vector>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    for(int j=0;j<m;j++)
    {
        int temp2;
        cin>>temp2;
        cout<<arr[temp2-1]<<endl;
    }
    return 0;
}