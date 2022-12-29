#include<iostream>
using namespace std;
const int N=100;
int n,m;//n 物品数量 m 背包容量
int w[N];//重量
int v[N];//价值
bool x[N]; //第i个是否已经加入背包
int weight=0;
int value=0;//用于计算物品的总价值和总重量
int result=0;//最优解
void flash_back(int i)
{
    
    if(i>n)//退出条件
    {
        if(value>result)
        {
            result=value;
        }
    }
    else{
        for(int j=0;j<=1;++j)//遍历当前节点的子节点
        {
            x[i]=j;
            if(j==0)//放当前第i个物品放入
            {
                flash_back(i+1);//下一层
            }
            else//不放当前第i个物品不放入
            {
                if((weight+w[i])<=m)
                {
                    weight+=w[i];
                    value+=v[i];
                    flash_back(i+1);//下一个物品
                    weight-=w[i];
                    value-=v[i];
                }
            }
        }

    }
    // return result;
}
int main()
{
    cin>>n>>m;//输入背包的容量和物品的个数
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    flash_back(1);
    cout<<result;//第一层开始
}
