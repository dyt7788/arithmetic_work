#include <iostream>
#include <vector>
using namespace std;
int n, q;

class cabinet
{
public:
    int i;
    int j;
    int k;
    cabinet(int i, int j, int k)
    {
        this->i = i;
        this->j = j;
        this->k = k;
    }
};
int main()
{
    cin >> n >> q;
    vector<cabinet> arr;
    for (int p = 0; p < q; p++)
    {
        int i, j, k;
        int f1;
        cin >> f1;
        if (f1 == 1)
        {
            cin >> i >> j >> k;
            cabinet temp = cabinet(i, j, k);
            arr.push_back(temp);
        }
        else if (f1 == 2)
        {
            cin >> i >> j;
            for (vector<cabinet>::iterator it = arr.begin(); it != arr.end(); it++)
            {
                if (it->i == i && it->j == j)
                {
                    cout << it->k<<endl;
                }
            }
        }
    }
    return 0;
}