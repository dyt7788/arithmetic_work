#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n;
  cin >> n;
  int sum_good=0;
  int sum_hege=0;
  int num_g=0;
  int num_h=0;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    if(temp>=60)
    {
      // sum_hege=sum_hege+temp;
      num_h++;
    }
    if(temp>=85)
    {
      // sum_good-sum_good+temp;
      num_g++;
    }
  }
  int result=num_h*100.0/n*1.0+0.5;
  int result1=num_g*100.0/n*1.0+0.5;
  // cout<<result<<endl;
  // cout<<result1<<endl;
  cout<<result<<"%\n"<<result1<<"%";
  return 0;
  
}