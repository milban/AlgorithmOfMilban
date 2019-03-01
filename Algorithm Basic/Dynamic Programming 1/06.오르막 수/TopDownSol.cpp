#include <iostream>
using namespace std;

int cache[10001][11];

void initCache()
{
	for(int i=0; i<10001; i++)
	{
		for(int j=0; j<11; j++)
			cache[i][j] = 0;
	}
}

int calAscentNum(int digitNum, int startNum)
{
		if(cache[digitNum][startNum]!=0)
				return cache[digitNum][startNum];
    int tmp = 0;
    if(digitNum==1)
        return 1;
    for(int nextNum=startNum; nextNum<=9; nextNum++)
    {
        tmp = (tmp + calAscentNum(digitNum-1, nextNum)) % 10007;
    }
    cache[digitNum][startNum] = tmp;
    return cache[digitNum][startNum];
}

int main()
{
    int digitNum;
    cin >> digitNum;
    int tmp = 0;
    for(int i=0; i<=9; i++)
    {
        tmp = (tmp + calAscentNum(digitNum, i)) % 10007;
    }
    cout << tmp << endl;
    return 0;
}