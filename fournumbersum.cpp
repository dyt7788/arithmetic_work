#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    if(nums.size()<4)
    {
        return result;
    }
    int a,b,left,right,len=nums.size();
    for(a=0;a<=len-4;a++)
    {
        if(a>0&&nums[a]==nums[a-1]) continue;
        for(b=a+1;b<=len-3;b++){
            if(b>a+1&&nums[b]==nums[b-1]) continue;
            left=b+1,right=len-1;//左右指针
            while(left<right)
            {
                if(nums[a]+nums[b]+nums[left]+nums[right]<target)
                    left++;
                else if(nums[a]+nums[b]+nums[left]+nums[right]<target)
                    right--;
                else{
                    result.push_back({nums[a],nums[b],nums[left],nums[right]});
                    while(left<right&&nums[left]==nums[left+1])
                        left++;
                    while(left<right&&nums[right-1]==nums[right])
                        right--;
                    left++;
                    right--;
                }
            }

        }
    }
    return result;

}
int main()
{

}