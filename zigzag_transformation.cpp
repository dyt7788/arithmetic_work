//Z自行变换 字符串做z字形变换
#include<iostream>
#include<string>
using namespace std;
//变换竖向的z
//以2*numrows-2为周期
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        string result;
        int len=s.size();
        int r=2*numRows-2;
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j+i<len;j+=r)
            {
                result+=s[j+i];//周期
                if(i!=0&&i!=numRows-1&&j+r-i<len)
                {
                    result+=s[j+r-i];
                }
            }
        }
        return result;
    }
};
int main()
{
    Solution s1;
    s1.convert("uiuoiowiyhkj",3);
}