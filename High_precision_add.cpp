//高精度加法
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> result;
void add(string a, string b)
{
    int flag = b.size() - 1;
    int cin = 0;
    int sum_add = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (flag >= 0)
        {
            sum_add = int(a.at(i)) + int(b.at(flag--)) + cin - 48 * 2;
        }
        else
        {
            sum_add = a.at(i) + cin - 48;
        }
        if (sum_add > 9)
        {
            cin = 1;
            if (i != 0)
            {
                sum_add = sum_add - 10;
            }
        }
        else
        {
            cin = 0;
        }
        result.insert(result.begin(), sum_add);
    }
    for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it;
    }
}
int main()
{

    string a, b;
    cin >> a >> b;
    int a_len = a.size();
    int b_len = b.size();
    if (a_len > b_len)
    {
        add(a, b);
    }
    else
    {
        add(b, a);
    }
    return 0;
}
