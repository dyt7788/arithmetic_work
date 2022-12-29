#include<iostream>
#include<vector>
using namespace std;
/*
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，
所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。
*/
//分析不同的情况就能得到正解
void display(vector<int> list)
{
    for(vector<int>::iterator it=list.begin();it!=list.end();it++)
    {
        // cout<<*it<<" ";
    }
}
string intToRoman(int num) {
    //获取num的各个位置的数值
    vector<int> num_list;
    string result="";
    while(num>0)
    {
        int digit;
        digit=num%10;
        num_list.push_back(digit);
        num=num/10;
    }
    // int flag=0;
    int len=num_list.size();
    for(int i=0;i<=len-1;i++)
    {
        if(i==0)//个位
        {
            if(num_list[i]<=3)
            {
                for(int j=0;j<num_list[i];j++)
                    result.insert(0,"I");
            }
            else if(num_list[i]==4)
            {
                result.insert(0,"IV");
            }
            else if(num_list[i]>=5&&num_list[i]<9)
            {
                result.insert(0,"V");
                for(int j=0;j<num_list[i]-5;j++)
                {
                    result.append("I");
                }
            }
            else if(num_list[i]==9)
            {
                result.insert(0,"IX");
            }
            
        }
        else if(i==1){//十位
                   if(num_list[i]<=3)
            {
                for(int j=0;j<num_list[i];j++)
                    result.insert(0,"X");
            }
            else if(num_list[i]==4)
            {
                result.insert(0,"XL");
            }
            else if(num_list[i]>=5&&num_list[i]<9)
            {
                result.insert(0,"L");
                for(int j=0;j<num_list[i]-5;j++)
                {
                    result.insert(1,"X");//头插发顺序有问题
                }
            }
            else if(num_list[i]==9)
            {
                result.insert(0,"XC");
            } 



        }
        else if(i==2)//百位
        {
            if(num_list[i]<=3)
            {
                for(int j=0;j<num_list[i];j++)
                    result.insert(0,"C");
            }
            else if(num_list[i]==4)
            {
                result.insert(0,"CD");
            }
            else if(num_list[i]>=5&&num_list[i]<9)
            {
                result.insert(0,"D");
                for(int j=0;j<num_list[i]-5;j++)
                {
                    result.insert(1,"C");
                }
            }
            else if(num_list[i]==9)
            {
                result.insert(0,"CM");
            }   
        }
        else{//千位
            if(num_list[i]<=3)
            {
                for(int j=0;j<num_list[i];j++)
                    result.insert(0,"M");
            }
        }
    }
    return result;
}
int main()
{
    cout<<intToRoman(1994);
}