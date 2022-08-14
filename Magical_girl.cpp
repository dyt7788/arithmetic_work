//矩阵旋转
//第一行两个整数 n,mn,m，表示方阵大小和魔法施放次数。
//接下来 m 行，每行 4 个整数 x,y,r,z，表示在这次魔法中，
// Scarlet 会把以第 xx 行第 yy 列为中心的 2r+1 阶矩阵按照某种时针方向旋转，
//其中z=0 表示顺时针，z=1 表示逆时针。

//旋转完成后要注意更新！！！！

#include <iostream>
using namespace std;
int a[502][502], b[502][502];
int x, y, r, z;
int n, m;
void change(int x, int y, int r, int z)
{
    int x1,y1;
    if (z == 0) //顺时针
    {
        x1 = x + r;
        y1 = y - r; //原来最后一行第一个
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                a[i][j] = b[x1][y1]; //第一行对于第一列
                x1--;
            }
            x1 = x + r;
            y1++; //第二列
        }
    }
    if(z==1)
    {
        x1 = x - r;
        y1 = y + r; //原来最后一行第一个
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                a[i][j] = b[x1][y1]; //第一行对于第一列
                x1++;
            }
            y1--;
            x1 = x - r;
             //第二列
        }
    }
}
void Synchronize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
}
int main()
{
 
    cin >> n >> m;
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = flag++;
            b[i][j] = a[i][j];
        }
    }

    for (int j = 0; j < m; j++)
    {
        cin >> x >> y >> r >> z;
        Synchronize();
        change(x, y, r, z);

    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}