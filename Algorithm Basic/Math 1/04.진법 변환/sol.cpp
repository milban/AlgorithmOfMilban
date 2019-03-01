#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int myCal(string num, int jinbub)
{
    int tmp = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            int nn = num[i] - '0';
            tmp += nn * pow(jinbub, num.length() - i - 1);
        }
        else
        {
            int nn = num[i] - 'A' + 10;
            tmp += nn * pow(jinbub, num.length() - i - 1);
        }
    }
    return tmp;
}

int main()
{
    int B;
    string N;
    cin >> N >> B;
    cout << myCal(N, B) << endl;
    return 0;
}