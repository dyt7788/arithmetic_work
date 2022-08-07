//洛谷算法玩具谜题
//玩具小人的朝向会影响下一步的位置
//小人朝内它的左边就是顺时针 右边就是逆时针
//小人朝外它的右边是顺时针
//输入的小人是逆时针的顺序
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class toy
{
public:
    int orient;
    string name;
}toys[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i < n; i++)
    {
        cin>>toys[i].orient>>toys[i].name;
    }
    int now=0;
    
    for (int i = 1; i <= m; i++)
    {
      cin>>x>>y;
      if(toys[now].orient==0&&x==0) now=(now+n-y)%n;
      else if(toys[now].orient==0&&x==1) now=(now+y)%n;
      else if(toys[now].orient==1&&x==0) now=(now+y)%n;
      else if(toys[now].orient==1&&x==1) now=(now+n-y)%n;
    }
    cout<<toys[now].name<<endl;
    return 0;
}