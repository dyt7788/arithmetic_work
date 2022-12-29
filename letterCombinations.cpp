#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
//使用回溯法
void backtrack(vector<string> &result,const unordered_map<char,string>&phonemap,const string &digits,int index,string&combination)
{
    if(index==digits.length())
    {
        result.push_back(combination);
    }
    else{
        char digit=digits[index];
        const string &letters=phonemap.at(digit);
        for(const char&letter:letters)
        {
            combination.push_back(letter);//第一个字母
            backtrack(result,phonemap,digits,index+1,combination);//往下
            combination.pop_back();//回到上一个节点
        }
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty())
    {
        return result;
    }
    unordered_map<char,string>symbolValues={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jk"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    }; 
    string combination;
    backtrack(result,symbolValues,digits,0,combination);
    return result;
}
int main()
{


}