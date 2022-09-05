//动态规划解法
//最长回文子串
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//输入：s = "cbbd"
// 输出："bb"
//暴力解法直接使用遍历子串的方法判断是否回文
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen=1;
        int n=s.length();
        int begin=0;//子串的长度
        if(n<2)
        {
            return s;//长度小于2就是一个字符一个字符是回文
        }
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {//列开始遍历
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);

    }
};
int main()
{
    Solution s1;
    cout<<s1.longestPalindrome("ccc");
}