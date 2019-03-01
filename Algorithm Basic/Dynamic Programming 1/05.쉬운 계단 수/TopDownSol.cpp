#include <iostream>
using namespace std;

int cache[101][11]; // N자리수에 대한 M으로 시작하는 계단 수의 개수

void initCache()
{
	for(int i=0; i<101; i++)
	{
		for(int j=0; j<11; j++)
			cache[i][j] = 0;
	}
}

int calStairNum(int digitNum, int startNum)
{
		if(cache[digitNum][startNum]!=0)
				return cache[digitNum][startNum];
    if(digitNum==1)
        return 1;
		if(startNum==0)
				cache[digitNum][startNum] = calStairNum(digitNum-1, startNum+1) % 1000000000;
    else if(startNum==9)
        cache[digitNum][startNum] = calStairNum(digitNum-1, startNum-1) % 1000000000;
    else
    {
        cache[digitNum][startNum] = (calStairNum(digitNum-1, startNum+1) + calStairNum(digitNum-1, startNum-1)) % 1000000000;
    }
		return cache[digitNum][startNum];
}

int main()
{
    int digitNum;
    cin >> digitNum;
    int tmp = 0;
    for(int i=1; i<=9; i++)
        tmp =(tmp + calStairNum(digitNum, i)) % 1000000000;
    cout << tmp << endl;
    return 0;
}