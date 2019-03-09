#include <iostream>
using namespace std;

#define SIZE 10000000

int isNotPrime[SIZE]; // 소수면 0

void eratosthenes()
{ // 에라스토테네스 해 구하기 1000만개 전부
	for (int i = 2; i*i < SIZE; i++)
		if (!isNotPrime[i])
			for (int j = i * i; j < SIZE; j += i)
				isNotPrime[j] = 1;
	isNotPrime[1] = 1;
}

int main()
{
    eratosthenes();
    int input;
    cin >> input;
    while(input!=1)
    {
        for(int i=2; i<SIZE; i++)
        {
            if(!isNotPrime[i] && (input%i == 0))
            {
                printf("%d\n", i);
                input = input/i;
				break;
            }
        }
    }
    return 0;
}