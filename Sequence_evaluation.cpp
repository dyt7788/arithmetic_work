#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//     int a[20190334];//不能定义在main函数里面 会爆栈 定义到全局
//     a[1]=1;
//     a[2]=1;
//     a[3]=1;
//     // cout<<a[1]<<a[2]<<a[3]<<endl;
//     for(int i=4;i<=20190324;i++)
//     {
//         a[i]=a[i-1]+a[i-2]+a[i-3];
//         a[i]=a[i]%10000;
//     }
//     cout<<a[20190324]<<endl;
//     return 0;
// }
const int N = 20190324 + 10;
const int INF = 0x3f3f3f3f;

int a[N];
int main()
{
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    for (int i = 4; i <= 20190324; i++){
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        a[i] %= 10000;
    }
    cout << a[20190324] << endl;
    return 0;
}
