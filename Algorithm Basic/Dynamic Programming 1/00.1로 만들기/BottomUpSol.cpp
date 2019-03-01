#include <iostream>
#include <algorithm>
using namespace std;

#define maxSize 1000001
int cache[maxSize] = {0,};
int last_pos = 1;

int makeOne(int input)
{
    if (input <= last_pos)
        return cache[input];
    for (int i = last_pos + 1; i <= input; i++)
    {
        cache[i] = cache[i - 1] + 1;
        if (i % 2 == 0)
            cache[i] = min(cache[i], cache[i / 2] + 1);
        if (i % 3 == 0)
            cache[i] = min(cache[i], cache[i / 3] + 1);
    }
    last_pos = input;
    return cache[input];
}

int main()
{
    int input;
    cin >> input;
    cout << makeOne(input) << endl;

    return 0;
}