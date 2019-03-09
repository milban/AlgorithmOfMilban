#include <iostream>
using namespace std;

int calFactorial(int num)
{
    if(num==0)
        return 1;
    if(num==1)
        return 1;
    return num*calFactorial(num-1);
}

int main()
{
    int input;
    cin >> input;
    cout << calFactorial(input) << endl;
    return 0;
}