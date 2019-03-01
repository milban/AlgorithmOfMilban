// 메모리 6044KB, 시간 52ms
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string convert2to8(string binary)
{
    string result = "";
    int tmp = 0;
    int cnt = 1;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        tmp += int(binary[i] - '0') * pow(2, cnt - 1);
        if (cnt == 3 || i == 0)
        {
            result += char(tmp + '0');
            cnt = 0;
            tmp = 0;
        }
        cnt++;
    }
    return result;
}

int main()
{
    string input;
    cin >> input;
    string result = convert2to8(input);
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}