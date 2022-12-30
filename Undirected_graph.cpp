#include <iostream>
using namespace std;

#define inf 99999999;
int e[4][4];
void add(char A1, char A2, int c)
{
    int a = A1 - 'A' + 1;
    int b = A2 - 'A' + 1;
    e[a][b] = c;
    e[b][a] = c;
}
void display(int a[])
{
       for (int i = 1; i <= 4; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int i, j, u, v;
    int n = 4;
    int dis[4] = {0};
    int book[4] = {0};
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                e[i][j] = 0;
            }
            else
            {
                e[i][j] = inf;
            }
        }
    }
    // 添加边
    add('A', 'B', 2);
    add('A', 'C', 1);
    add('C', 'B', 3);
    add('B', 'D', 1);
    // display();
    for (i = 1; i <= n; i++)
    {
        dis[i] = e[1][i]; // 存放选择的节点 存放选择走的系欸但
    }
    cout<<"dis:";
    display(dis);
    book[1] = 1; // 是否已经访问这个节点
    for (i = 1; i <= n; i++)
    {
        int min = inf;
        for (j = 1; j <= n; j++)//找到每一行最小值
        {
            if (book[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                cout<<"dis1:"<<dis[j];
                u = j;
            }
        }
        cout<<"u:"<<u<<endl;
        book[u] = 1;
        cout<<"book:";
        display(book);
        for (v = 1; v <= n; v++)
        {
            if(dis[v]>dis[u]+e[u][v]&& e[u][v]<99999999 )
            {
                cout<<"dis[v]:"<<dis[v]<<endl;
                dis[v]=dis[u]+e[u][v];
                cout<<"dis:";
                display(dis);
            }
        }
    }
    cout<<dis[4];
}