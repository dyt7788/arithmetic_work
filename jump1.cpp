#include<bits/stdc++.h>
using namespace std;
bool jump(vector<int>& nums)
{
    int maxPos=0,n=nums.size(),end=0,step=0;
    for(int i=0;i<n-1;++i)
    {
        if(maxPos>=i){
            maxPos=max(maxPos,i+nums[i]);
            if(i==end){//第一步一定会跳
                cout<<i<<endl;
                end=maxPos;
                // ++step;
            }
        }
    }
    if(end>=n-1)
    {
        return true;
    }
    return false;
    // return step;
}
int main()
{
    vector<int> nums={2,3,1,1,4};
    cout<<jump(nums);
}