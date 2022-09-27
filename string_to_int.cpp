#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        // s=s.trim();//
        int length = s.size(), p = 0, num, sign = 1, result = 0;
		char ch;
		while (p < length && s[p] == ' ')//读入前导空格 开始
		{
			++p;
		}
		if (s[p] == '+')
		{
			++p;
		}
		else if (s[p] == '-')
		{
			sign = -1;//负数标记
			++p;
		}
		for (; p < length; ++p)
		{
			ch = s[p];
			if (isdigit(ch))
			{
				num = ch - '0';
				if (result > INT_MAX / 10 || result == INT_MAX / 10 && num > INT_MAX % 10)
				{
					return INT_MAX;//越界
				}
				else if (result < INT_MIN / 10 || result == INT_MIN / 10 && -num < INT_MIN % 10)
				{
					return INT_MIN;//越界
				}
				result = result * 10 + sign * num;
			}
			else
			{
				break;
			}
		}
		return result;
    }
};
int main()
{
    Solution s1;
    cout<<s1.myAtoi("words and 987");
}