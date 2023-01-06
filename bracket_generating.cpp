#include<bits/stdc++.h>
using namespace std;
void backtrack(vector<string>& ans,string &cur,int open,int close,int n )
{
    if(cur.size()==n*2)//以及包含六个元素
    {
        ans.push_back(cur);
        return ;
    }
    if(open<n)//左括号的个数
    {
        cur.push_back('(');
        backtrack(ans,cur,open+1,close,n);
        cur.pop_back();
    }
    if(close<open)
    {
        cur.push_back(')');
        backtrack(ans,cur,open,close+1,n);
        cur.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    backtrack(result,current,0,0,n);
    return result;

}
void display(vector<string> s)
{
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        cout<<s[i]<<" ";
    }

}
int main()
{
    int n;
    cin>>n;
    vector<string> result;

    result=generateParenthesis(n);
    display(result);
}
