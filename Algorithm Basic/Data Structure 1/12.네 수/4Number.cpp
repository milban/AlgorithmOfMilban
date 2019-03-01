#include <iostream>
using namespace std;

int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    string front = a + b, back = c + d;
    double result_d = stod(front) + stod(back);
    string result_s = to_string(result_d);
    result_s.erase(result_s.size() - 7, result_s.size());
    cout << result_s << endl;
    return 0;
}