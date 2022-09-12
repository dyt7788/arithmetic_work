#include<iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int len=s.size();
        int result=0;
        int flag=1;
        for(int i=0;i<len;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                result=result*10+s[i]-'0';
            }
            if(s[i+1]<'0'||s[i+1]>'9')
            {
                   continue;
            }
            if(s[i]=='-')
            {
                if(s[i+1]>='0'&&s[i+1]<='9')
                {
                    flag=-1;
                }
            }
            if(s[i]==' ')
            {
                if(s[i+1]>='0'&&s[i+1]<='9')
                {
                    return 0;
                }
            }
        }
        return result*flag;
    }
};
int main()
{
    Solution s1;
    cout<<s1.myAtoi("words and 987");
}