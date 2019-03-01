#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        bool isPrime = true;
        if (arr[i] == 1)
            isPrime = false;
        for (int j = 2; j < arr[i] && isPrime; j++)
        {
            if (arr[i] % j == 0)
                isPrime = false;
        }
        if (isPrime)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}