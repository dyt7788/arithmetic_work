#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class substance
{
public:
    double w;
    double v;
    int embrace=0;
    void display()
    {
        cout<<"weight:"<<w<<"     value:"<<v<<endl;
    }
};

int n,m;//n 物品数量 m 背包容量
int currentw=0;//当前背包重量
int currentv=0;//当前背包价值
int result=0;//最优解
// int embrace[100];//物品已经包含
vector<substance> pre;
static bool compare(const substance v1,const substance v2)
{
    return (v1.v/v1.w)>(v2.v/v2.w);
}
void dis_pre()
{
    for(vector<substance>::iterator it=pre.begin();it!=pre.end();it++)
    {
        it->display();
    }

}
double bound(int i)
{
    double Remaining_weight=m-currentw;
    double bound_v=currentv;//当前价值
    while(i<n&&pre.at(i).w<=Remaining_weight)
    {
        Remaining_weight-=pre.at(i).w;
        bound_v+=pre.at(i).v;
        i++;
    }
    if (i<n)
    {
        bound_v=pre.at(i).v/pre.at(i).w*Remaining_weight;
    }
    return bound_v;
}
void flash_back(int i)
{
    
    if(i>n-1)//退出条件
    {
            result=currentv;
            return ;
    }
    cout<<"pre_weight:"<<pre.at(i).w<<endl;
    cout<<"current_weight:"<<currentw<<endl;
    if((currentw+pre.at(i).w)<=m)
    {
        // cout<<"1"<<endl;
        currentw+=pre.at(i).w;
        currentv+=pre.at(i).v;
        pre.at(i).embrace=1;
        flash_back(i+1);//下一个物品
        currentw-=pre.at(i).w;
        currentv-=pre.at(i).v;
    }
    // cout<<"currentw"<<currentw<<endl;
    if(bound(i+1)>result)
        flash_back(i+1);//超过界限直接下一层
    // return result;
}
int main()
{
    cout<<"number and weight:"<<endl;
    cin>>n>>m;
    // cin>>m;
    cout<<"w and v"<<endl;
    for(int i=0;i<n;i++)
    {
        substance s1;
        cin>>s1.w>>s1.v;
        pre.push_back(s1);
    }
    sort(pre.begin(),pre.end(),compare);
    flash_back(0);
    cout<<"result:"<<result<<endl;
    // cout<<result;
    dis_pre();
}