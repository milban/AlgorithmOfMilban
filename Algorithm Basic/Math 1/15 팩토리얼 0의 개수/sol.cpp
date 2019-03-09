#include <iostream>
using namespace std;

#define SIZE 10000000

int isNotPrime[SIZE]; // 소수면 0

void eratosthenes()
{ // 에라스토테네스 해 구하기 1000만개 전부
    for (int i = 2; i * i < SIZE; i++)
        if (!isNotPrime[i])
            for (int j = i * i; j < SIZE; j += i)
                isNotPrime[j] = 1;
    isNotPrime[1] = 1;
}

int main()
{
    eratosthenes();
    int input;
    int cnt2 = 0, cnt5 = 0;
    cin >> input;
    for (int j = 2; j <= input; j++)
    {
        int curNumt = j;
        while (curNumt != 1)
        {
            for (int i = 2; i < SIZE; i++)
            {
                if (!isNotPrime[i] && (curNumt % i == 0))
                {
                    if (i == 2)
                        cnt2++;
                    else if (i == 5)
                        cnt5++;
                    curNumt = curNumt / i;
                    break;
                }
            }
        }
    }

    int result = (cnt2 > cnt5 ? cnt5 : cnt2);
    cout << result << endl;
    return 0;
}