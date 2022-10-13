//最大字段和
//分治法
#include<iostream>
using namespace std;
//分段左右进行查找最大子段和
#define max 6
int maxsubsum(int *a,int left,int right)
{
    int sum=0;
    if(left==right)
    {
        sum=a[left]>0?a[left]:0;//负数算为0
    }
    else
    {
        int center=(left+right)/2;//中间值
        int leftsum=maxsubsum(a,left,center);
        int rightsum=maxsubsum(a,center+1,right);
        int s1=0;
        int lefts=0;
        for(int i=center;i>=left;i--)//计算左边最大字段和
        {
            lefts+=a[i];
            if(lefts>s1)
                s1=lefts;
        }
        int s2 = 0;//记录右段最大字段和
		int rights = 0;
		for (int i = center + 1; i <= right; i++)
		{
			rights += a[i];
			if (rights > s2)
				s2 = rights;
		}
        sum=s1+s2;
        if(sum<leftsum)
        sum=leftsum;
        if(sum<rightsum)
        sum=rightsum;
  }
  return sum;
}
int maxsum(int n,int *a)
{
    return maxsubsum(a,1,n);
}
int main()
{
    int a[max];
    for(int i=1;i<=max;i++)
    {
        cin>>a[i];
    }
    cout<<maxsum(max,a);
}