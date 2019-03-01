#include <iostream>
#include <algorithm>
using namespace std;

int cache[1001] = {0,};

void initCache()
{
    cache[0] = 1;
    cache[1] = 1;
}

int numOfWayFillTile(int width)
{
    if(cache[width]!=0)
        return cache[width];
    for(int i=2; i<=width; i++)
    {
        cache[i] = (cache[i-2] + cache[i-1]) % 10007;
    }
    return cache[width];
}

int main()
{
    int width;
    cin >> width;
	initCache();
    cout << numOfWayFillTile(width) << endl;
    return 0;
}