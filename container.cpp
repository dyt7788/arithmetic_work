#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。
*/
int maxArea(vector<int>& height) {
    int max_result=0;
    int i=0;
    int j=height.size()-1;
    while(i<j)
    {
        max_result=height[i]<height[j]?
        max(max_result,(j-i)*height[i++]):max(max_result,(j-i)*height[j--]);//左比右低 左边指针移动 否则右边指针移动
    }
    return max_result;
}
int main()
{
   vector<int> lis;
   lis.push_back(1);
   lis.push_back(8); 
   lis.push_back(6);
   lis.push_back(2); 
   lis.push_back(5);
   lis.push_back(4);
   lis.push_back(8);
   lis.push_back(3);
   lis.push_back(7);
   maxArea(lis);
   return 0;  
}