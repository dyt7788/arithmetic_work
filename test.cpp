#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 510;
int n, m;
int dist[N],g[N][N];
bool st[N]; //标记是否在集合中  
 
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)
            if(!st[j] && (t==-1 || dist[j] < dist[t]))
                t = j;
                
        //if(t == n) break; //可以提前break, 优化时间开销 
        
        st[t] = true;
        for(int j = 1; j <= n; j ++)    //更新集合中的最短路径
            dist[j] = min(dist[j], dist[t]+g[t][j]);
        
    }
    
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}
int main()
{
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof g);
 
    int a,b,c;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);//边数较多,scanf省时
        g[a][b] = min(c, g[a][b]);  //由题意,图中可能存在重边和自环
    }
    
    cout << dijkstra();
}