//矩阵取数
//
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int a[200] = {0};
    int f[200] = {0};
    for (int k = 1; k <= n; k++){ //对于每一行去最大值
        for (int i = 1; i <= m; i++)
            cin >> a[i];
    for (int i = 0; i <= m; i++)
        f[i] = 0;
    f[1] = a[m]; //对于每一行
    f[2] = a[1];
    for (int i = 2; i <= m; i++)
        for (int j = m; j >= 1; j--)
        {

            int x = (f[j - 1] != 0) * (f[j - 1] + i * a[j - 1]);
            int y = (f[j] != 0) * (f[j] + i * a[j + m - i]);
            f[j] = (x > y ? x : y);
        }
    int max=0;
    for(int i=1;i<=m;i++)
       if (f[i]>max) max=f[i];
    sum+=max;
    }
    cout<<sum<<endl;
    return 0;
}