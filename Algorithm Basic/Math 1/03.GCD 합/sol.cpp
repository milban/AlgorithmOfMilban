#include <iostream>
using namespace std;

int *arr;
int N;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long calSumGCD()
{
    long long tmp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            tmp += gcd(arr[i], arr[j]);
        }
    }
    return tmp;
}

int main()
{
    int T, A, B;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        arr = new int[N];
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            arr[j] = tmp;
        }
        cout << calSumGCD() << endl;
    }
    return 0;
}