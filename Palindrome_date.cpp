#include <iostream>
#include <sstream>
using namespace std;
int mouths[13] = {0, 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31}; // 每个月份对应的天数
string iitos(int n)                                               // int 转string
{
    string q;
    stringstream ss;
    ss << n;
    return ss.str();
}
bool check(int m) // 判断是否合法日期
{
    int year = m / 10000;
    int mouth = m % 10000 / 100;
    int day = m % 100;
    // cout<<year<<" "<<mouth<<" "<<day;
    if (!day || mouth < 0 || mouth > 12)
    {
        // cout << 1;
        return false;
        
    }
    if (mouth == 2)
    {
        if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
        {
            if (day > 29)
            {
                // cout<<1;
                return false;
            }
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    else
    {
        if (day > mouths[mouth ])
        {
            // cout << 1;
            return false;
            
        }
    }
    return true;
}
bool check1(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}
bool check2(string s)
{
    if (check1(s))
    {
        if (s[0] != s[2] || s[1] != s[3] || s[0] == s[1])
            return false;
        return true;
    }
    return false;
}
int main()
{
    // 请在此输入您的代码
    int data;
    cin >> data;
    int flag = 0;
    //   string s=iitos(data);
    // cout << check(data);
      for(int i=data+1;i<99999999;i++)
      {
        if(check(i))
        {
            string s=iitos(i);
            if(check1(s)&&!flag)
            {
                cout<<i<<endl;
                flag=1;
            }
            if(check2(s))
            {
                cout<<i<<endl;
                return 0;
            }
        }
        }
    return 0;
}