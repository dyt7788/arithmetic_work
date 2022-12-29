//括号匹配 使用stack
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
bool isValid(string s) {
    int len=s.size();
    if(len%2==1)//不是偶数肯定就不匹配
    {
        return false;
    }
    unordered_map<char,char> pairs={
        {')','('},
        {']','['},
        {'}','{'}
    };
    stack<char> stk;
    //字符串遍历
    for(char ch:s){
        if(pairs.count(ch)){//就是判断是否为又括号
            if(stk.empty()||stk.top()!=pairs[ch]){
                return false;
            }
            stk.pop();
        }
        else{//左括号就压
            stk.push(ch);
        }
    }
    return stk.empty();
}
int main()
{
    string s="{}(){)}";
    isValid(s);
}