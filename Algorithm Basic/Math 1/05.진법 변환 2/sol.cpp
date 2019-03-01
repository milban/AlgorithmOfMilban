#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string myCal(int num, int jinbub)
{
    string result = "";
    while (num > 0)
    {
        int tmp = num % jinbub;
        char c_tmp;
        if (tmp >= 10)
        {
            c_tmp = char(tmp - 10 + 'A');
        }
        else
        {
            c_tmp = char(tmp + '0');
        }
        result += c_tmp;
        num = num / jinbub;
    }
    return result;
}

int main()
{
    int B;
    int N;
    cin >> N >> B;
    string result = myCal(N, B);
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}