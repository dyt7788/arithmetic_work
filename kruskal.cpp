#include <cstdio>
#include <cstdlib>
#include<iostream>
#define MAXN 10000 + 10
using namespace std;
class edge{
    public:
         int a,b,weight;//存放每一个边的信息 a为起始节点，b为结束节点
}; 
int n,m;//n为顶点数 m为边数
int parent[MAXN];//源头
edge e_list[MAXN];
void display()
{
    for(int i=0;i<m;i++)
    {
        cout<<e_list[i].a<<" "<<e_list[i].b<<" "<<e_list[i].weight<<" "<<endl;
    }
}
void init_uf()//初始化并查集 以及源头数组
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;//都为-1
    }
}
int find(int i)//
{
 	int temp;
	//查找位置
	for(temp = i; parent[temp] >= 0; temp = parent[temp]);
	//压缩路径
	while(temp != i){
		int t = parent[i];
		parent[i] = temp;//直接赋值为i
		i = t;
	}
	return temp;//没有找到返回的就是i 无源头就是本身

}
void merge(int x,int y)//合并源
{
    int r1 = find(x);
	int r2 = find(y);
	int tmp = parent[r1] + parent[r2]; //两个集合节点数的和
	if(parent[r1] > parent[r2]){
		parent[r1] = r2;
		parent[r2] = tmp;
	}else{
		parent[r2] = r1;
		parent[r1] = tmp;
	}

}
int cmp(const void * a,const void *b)
{
    return ((edge*)a)->weight-((edge*)b)->weight;//没有确定指针类型，先对a,b转化一下类型 返回比较值 用于排序
}
int kruskal()
{
    int sum=0;
    //按照边排序
    qsort(e_list,n,sizeof(edge),cmp);
    for(int i=0;i<n;i++)
    {
        int a,b;
        a=find(e_list[i].a);//起点的源头
        b=find(e_list[i].b);//终点的源头
        // cout<<a<<"    "<<b;
        if(a!=b)//源头不同就进行合并
        {
            merge(a,b);
            sum=sum+e_list[i].weight;
        }
    }
    return sum;
}
int main()
{
    cin>>n>>m;
    init_uf();//初始化并查集
    for(int i=0;i<m;i++)
    {
        cin>>e_list[i].a>>e_list[i].b>>e_list[i].weight;
    }
    // display();
    cout<<kruskal();
    return 0;
}