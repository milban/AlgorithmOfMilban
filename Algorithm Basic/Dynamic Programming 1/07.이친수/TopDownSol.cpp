#include <iostream>
using namespace std;

long long cache[91][2];

void initCache()
{
	for(int i=0; i<91; i++)
	{
		for(int j=0; j<2; j++)
			cache[i][j] = 0;
	}
}

long long calPinaryNum(int digitNum, int startNum)
{
	if(cache[digitNum][startNum]!=0)
		return cache[digitNum][startNum];
	if(digitNum==1)
		return 1;
	if(startNum==1) // 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
	{
		cache[digitNum][startNum] = calPinaryNum(digitNum-1, 0);
	}
	else if(startNum==0)
	{
		cache[digitNum][startNum] = calPinaryNum(digitNum-1, 0) + calPinaryNum(digitNum-1, 1);
	}
	return cache[digitNum][startNum];
}

int main()
{
    int digitNum;
    cin >> digitNum;
	// 이친수는 0으로 시작하지 않는다. -> 1로만 시작하므로 성립
	cout << calPinaryNum(digitNum, 1) << endl;
    return 0;
}