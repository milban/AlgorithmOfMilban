// 메모리 : 1988KB, 시간 : 0ms
#include <iostream>
#include <algorithm>
using namespace std;

int cache[1001] = {0,};

int numOfWayFillTile(int width)
{
    if(width==0)
        return 1;
	if(cache[width]!=0)
		return cache[width];
	if(width==1)
		cache[width] = numOfWayFillTile(width-1) % 10007;
  else
		cache[width] = (numOfWayFillTile(width-2) + numOfWayFillTile(width-1)) % 10007;
	return cache[width];
}

int main()
{
    int width;
    cin >> width;
    cout << numOfWayFillTile(width)<< endl;
    return 0;
}