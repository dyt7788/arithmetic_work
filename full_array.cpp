//全排列使用递归来实现
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> full(string s)
{
    vector<string> answer;
    int len=s.size();
    if(len<=1)
    {
        vector<string> ans;
        ans.push_back(s);
        return ans;
    }
    else{
        for(int i=0;i<len;i++)
        {
            string temp=s.substr(0,i)+s.substr(i+1,len);
            vector<string> ans=full(temp);
            for(vector<string>::iterator it=ans.begin();it!=ans.end();it++)
            {
                string result=s[i]+*it;
                answer.push_back(result);
            }
        }
    }
    return answer;
}
int main()
{
    vector<string>result=full("ABC");
    for(vector<string>::iterator it=result.begin();it!=result.end();it++)
    {
        cout<<*it<<endl;
    }
    cout<<result.size();
    
}