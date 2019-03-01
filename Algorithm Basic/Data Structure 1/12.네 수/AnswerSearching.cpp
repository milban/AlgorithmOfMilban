#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
 
    string s1 = a + b;
    string s2 = c + d;
 
    long long n1 = stoll(s1);
    long long n2 = stoll(s2);
 
    cout << n1 + n2 << '\n';
    return 0;
}