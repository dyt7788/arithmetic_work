//高精度阶乘
//就是将数组看成列竖式的数组
//最右边对应就是个位
#include<iostream>
using namespace std;
int main()
{
    int a[1005]={0},b[1005]={0};
    int n;
    a[0]=b[0]=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        for(int j=0;j<100;j++)
            b[j]*=i;//每一个数组元素进行 每一个数组里面存放的
            //是n的阶乘
        for(int j=0;j<100;j++)//对b数组进行再一次遍历 
            if(b[j]>9)//大于9时
            {
                b[j+1]+=b[j]/10; 
                b[j]%=10;
            }
        for(int j=0;j<100;j++)
        {
            a[j]+=b[j];
            if(a[j]>9)
            {
                a[j+1]+=a[j]/10;
                a[j]%=10;

            }
        }
    }
    int i;
    for (i=100;i>=0&&a[i]==0;i--);
    for (int j=i;j>=0;j--)
        cout<<a[j];
    return 0;
}
