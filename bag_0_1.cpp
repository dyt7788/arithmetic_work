#include <iostream>
#include <vector>
using namespace std;
#define max(N1, N2) N1 > N2 ? N1 : N2
int main()
{
    vector<int> w, v;
    vector<int> f;
    int V, n;
    cin >> V >> n;

    w.push_back(0);
    v.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int cur_w, cur_v;
        cin >> cur_w >> cur_v;
        w.push_back(cur_w);
        v.push_back(cur_v);
    }
    f = vector<int>(V + 1, 0); //分配空间并且初始化为0
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= w[i]; j--)//当前空间
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    int ans = f[V];
    cout << ans << endl;

    return 0;
}