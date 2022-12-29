#include<iostream>
#include<unordered_map>
using namespace std;
/*
给定一个罗马数字，将其转换成整数。使用键值对
*/
int romanToInt(string s) {
    unordered_map<char,int>symbolValues={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    int ans=0;
    int n=s.length();
    for(int i=0;i<n;++i)
    {
        int value=symbolValues[s[i]];//获取当前的值
        if(i<n-1&&value<symbolValues[s[i+1]]){
            ans-=value;//找到规律都是前者大于后者 如果是小于
        }else{
            ans+=value;
        }
    }
    return ans;
}
int main()
{
    cout<<romanToInt("IV");
}