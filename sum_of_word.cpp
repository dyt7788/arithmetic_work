//找出单词中出现次数最多的字母
#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string input;
  cin>>input;
  int count[26]={0};
    for(char ch:input)
  {
    // cout<<ch;
    count[ch-'a']++;
  }
  int max=0;
  char result;
  for(int i=0;i<26;i++)
  {
     if(count[i]>max)
     {
        max=count[i];
        result=i+'a';
     }
  }
  cout<<result<<"\n"<<max;
  return 0;
}