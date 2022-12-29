#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*三个数的和与目标值相近的*/
int threeSum(vector<int>& nums,int target) {
    int len=nums.size();
    // if(len<3) return {};//int数组长度小于三 没有办法实现三个数的和
    int res=nums[0]+nums[1]+nums[2];//结果保存位置
    sort(nums.begin(),nums.end());//排序
    for(int i=0;i<=len-3;i++)
    {
        int left=i+1;//双指针
        int right=len-1;
        while(left<right)
        {
            int temp=nums[left]+nums[right]+nums[i];
            if(temp>target)
            {
                res=abs(temp-target)>abs(target-res)?res:temp;
                right--;//大于
            }
            else if(nums[left]+nums[right]<-nums[i])
            {
                left++;
                res=abs(temp-target)>abs(target-res)?res:temp;
            }
            else{
                return target;
            }

        }
    }
    return res;
}