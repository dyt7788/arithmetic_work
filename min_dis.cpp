#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
class point
{ //坐标类
public:
    int x;
    int y;
};
point a[10001];
int temp[10001];
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2))); //求两个点的距离
}
bool comparexy(const point &a, const point &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
bool comparey(int p, int q)
{
    return a[p].y < a[q].y;
}
double merge(int left, int right)
{
    if (left == right)
        return INT_MAX;
    else if (left + 1 == right)
    {
        return dis(a[left].x, a[left].y, a[right].x, a[right].y);
    } //遍历的退出条件
    else
    {
        int m = (left + right) / 2; //中间位置
        double dis1 = merge(left, m);
        double dis2 = merge(m + 1, right);
        double d = min(dis1, dis2);
        // cout<<d;
        int p = 0;
        // while()
        for (int i = left; i <= right; i++)
        {
            if (abs(a[i].x - a[m].x) <= d)
            {
                temp[p++] = i; //找到与分割平面还要小的距离
            }
        }
        sort(temp, temp + p, comparey); //根据y进行排序
        for (int i = 0; i < p; i++)     //距离分割平面附近点的距离
        {
            for (int j = i + 1; j < p && (a[temp[i]].y - a[temp[j]].y) < d; j++)
            {
                double dis3 = dis(a[i].x, a[i].y, a[j].x, a[j].y);
                if (d > dis3)
                    d = dis3;
            }
        }
        return d;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n, comparexy);
    double answer = merge(0, n - 1);
    cout << answer;
}