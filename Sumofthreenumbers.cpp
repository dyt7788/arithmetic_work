#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*三个数的和 和的值为0*/
vector<vector<int>> threeSum(vector<int>& nums) {
    int len=nums.size();
    if(len<3) return {};//数组长度小于三 没有办法实现三个数的和
    vector<vector<int>>res;//结果保存位置
    sort(nums.begin(),nums.end());//排序
    for(int i=0;i<len;i++)
    {
        if(nums[i]>0) return res;//大于0后面的和不可能等于0
        if(i>0&&nums[i]==nums[i-1]) continue;//重复
        int left=i+1;//双指针
        int right=len-1;
        while(left<right)
        {
            if(nums[left]+nums[right]>-nums[i])
                right--;//大于
            else if(nums[left]+nums[right]<-nums[i])
                left++;
            else{
                //和为0
                res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                left++;
                right--;
                //去重 第二个数和第三个数不能重复
                while(left<right&&nums[left]==nums[left-1]) left++;
                while(left<right&&nums[right]==nums[right+1]) right--;
            }

        }
    }
    return res;
}

int main()
{
    
}