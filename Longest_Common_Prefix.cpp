#include<iostream>
/*最长公共前缀*/
#include<vector>
using namespace std;
string compare(const string&str1,const string &str2)
{
    int length=min(str1.size(),str2.size());
    int index=0;
    while(index<length&&str1[index]==str2[index]){
        ++index;//两个字符串相等的位置
    }
    return str1.substr(0,index);
}
string longestCommonPrefix(vector<string>& strs) {
    if(!strs.size())
    {
        return "";
    }
    int len=strs.size();
    string result=strs[0];
    for(int i=1;i<len;++i)
    {
        result=compare(result,strs[i]);
        if(!result.size())
        {
            break;
        }
    }
    return result;
}

int main()
{
    vector<string> list;
    list.push_back("love");
    list.push_back("lo");
    cout<<longestCommonPrefix(list);
}