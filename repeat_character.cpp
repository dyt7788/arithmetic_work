//最长无重复长度
// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<char> lookup;
        int maxstr=0;//最大长度
        int left=0;//右边的标志
        for(int i=0;i<s.size();i++)
        {
            while(lookup.find(s[i])!=lookup.end())//有重复
            {
                lookup.erase(s[left]);//集合去掉
                left++;//在集合中没有
            }
            maxstr=max(maxstr,i-left+1);//当前位置
            lookup.insert(s[i]);
        }
        return maxstr;
    }
};
int main()
{
    Solution s1;
    cout<<s1.lengthOfLongestSubstring("pwwkew");

}