//两个数组合并的中位数
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int slove(const vector<int>& nums1,const vector<int>& nums2,int k)
    {
        int m=nums1.size();
        int n=nums2.size();
        int index1=0,index2=0;
        //其中一个数组位空
        while(true){
            if(index1==m)
            {
                return nums2[index2+k-1];
            }
            if(index2==n)
            {
                return nums1[index1+k-1];
            }
            if(k==1){
                return min(nums1[index1],nums2[index2]);
            }
            int newindex1=min(index1+k/2-1,m-1);
            int newindex2=min(index2+k/2-1,n-1);
            int pivot1=nums1[newindex1];
            int pivot2=nums2[newindex2];
            if(pivot1<=pivot2){
                k-=newindex1-index1+1;
                index1=newindex1+1;//更新数组1的标志
            }
            else{
                k-=newindex2-index2+1;//更改k值长度变小
                index2=newindex2+1;//更新数组二的标志
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           //合并的话要花费很多时间和空间
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return slove(nums1, nums2, (totalLength + 1) / 2);//奇数的情况
        }
        else {
            return (slove(nums1, nums2, totalLength / 2) + slove(nums1, nums2, totalLength / 2 + 1)) / 2.0;//偶数要加两个所以调用两次函数
        }
    }
};