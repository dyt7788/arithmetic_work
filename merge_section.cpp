//合并区间
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int len=intervals.size();
    if(len==0)
    {
        return {};
    }
    vector<vector<int>> result;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<intervals.size();++i)
    {
        int l=intervals[i][0],r=intervals[i][1];//每一个区间的左右值
        if(!result.size()||result.back()[1]<l){//result最上面的一个区间右区间小于左 就说明已经没有要合并的了
            result.push_back({l,r});//直接将当前加入到vector中
        }
        else{
            result.back()[1]=max(result.back()[1],r);//更新右区间
        }
    }
    return result;
}
int main()
{

}
