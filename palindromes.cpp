#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
         //将x存放到数组中
         int a[10001];
         int i=0;
         if(x<0)
         {
            return false; 
         }
         while(x<0)
         {
             int flag=x%10;
             a[i++]=flag;
             x=x/10;
         }
        //  cout<<i<<endl;
         for(int j=0;j<i;j++)
         {
            //  cout<<a[j]<<endl;
             if(a[j]!=a[i-j-1])
                return false;
         }
         return true;
    }
};
int main()
{
    Solution s1;
    if(s1.isPalindrome(-1221))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}