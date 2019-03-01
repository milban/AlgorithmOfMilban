#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int *arr;
int arrSize;

vector<int> convertAtoB(int A, int B)
{
    int tenSys = 0;
    vector<int> result;
    for (int i = 0; i < arrSize; i++)
    {
        tenSys += arr[i] * pow(A, i);
    }
    while (tenSys > 0)
    {
        int tmp = tenSys % B;
        tenSys = tenSys / B;
        result.push_back(tmp);
    }
    return result;
}

int main()
{
    int A, B;
    cin >> A >> B >> arrSize;
    arr = new int[arrSize];
    for (int i = arrSize - 1; i >= 0; i--)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    vector<int> result = convertAtoB(A, B);
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}