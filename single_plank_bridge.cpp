/*
突然，你收到从指挥部发来的信息，
敌军的轰炸机正朝着你所在的独木桥飞来！
为了安全，你的部队必须撤下独木桥。
独木桥的长度为 LL，士兵们只能呆在坐标为整数的地方。
所有士兵的速度都为 11，
但一个士兵某一时刻来到了坐标为 00 或 L+1L+1 的位置，他就离开了独木桥。
每个士兵都有一个初始面对的方向，
他们会以匀速朝着这个方向行走，
中途不会自己改变方向。但是，如果两个士兵面对面相遇，
他们无法彼此通过对方，于是就分别转身，继续行走。
转身不需要任何的时间。*/
#include <iostream>
using namespace std;
int main()
{
    int n,l,p,maxv=0,minv=0;
    cin>>l>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p;
        maxv=max(maxv,max(l-p+1,p));
        minv=max(minv,min(l-p+1,p));
    }
    cout<<minv<<" "<<maxv;
    return 0;
}