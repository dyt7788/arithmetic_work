//最长回文子串
#include<iostream>
#include<string>
using namespace std;
//输入：s = "cbbd"
// 输出："bb"
//暴力解法直接使用遍历子串的方法判断是否回文
class Solution {
public:
    bool is_palindromic(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[s.size()-i-1])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxlen=1;
        int size=s.size();
        int length=0;//子串的长度
        if(size<2)
        {
            return s;//长度小于2就是一个字符一个字符是回文
        }
        else{
            for(int i=0;i<size;i++)
            {
                for(int j=i+1;j<size;j++)
                {
                    if(is_palindromic(s.substr(i,j)))
                    {
                        length=j-i+1;
                        maxlen=i;
                    }
                }
            }
        }
        return s.substr(maxlen,length);
    }
};
int main()
{
    Solution s1;
    cout<<s1.longestPalindrome("cbbd");
}