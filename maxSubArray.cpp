#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>&nums)
{
    int pre=0,maxAns=nums[0];
    for(const auto &x:nums)
    {
        // cout<<x<<endl;
        pre=max(pre+x,x);
        cout<<pre<<endl;
        maxAns=max(maxAns,pre);
    }
    return maxAns;
}
int main()
{
    vector<int> nums={5,4,-1,7,8};
    cout<<maxSubArray(nums);
}