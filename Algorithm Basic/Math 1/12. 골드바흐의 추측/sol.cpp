#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int num)
{
    if(num==1)
        return false;
    for(int i=2; i<sqrt(num); i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

int main()
{
    int input;
    cin >> input;
    while(input!=0)
    {
        bool existAns = false;
        for(int i = input; i>input/2; i--)
        {
            if(IsPrime(i))
            {
                if(IsPrime(input-i))
                {
                    printf("%d = %d + %d\n", input, input-i, i);
                    existAns = true;
                    break;
                }
            }
        }
        if(!existAns)
            printf("Goldbach's conjecture is wrong.\n");
        cin >> input;
    }

    return 0;
}