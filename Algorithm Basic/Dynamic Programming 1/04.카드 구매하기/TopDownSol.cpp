#include <iostream>
#include <algorithm>
using namespace std;

int cache[1001] = {0,};
int* cardPackPrice;

int purchaseCard(int cardNum)
{
	if(cache[cardNum]!=0)
		return cache[cardNum];
	if(cardNum==0)
	{
		return 0;
	}
	int tmp=0;
	for(int i=1; i<=cardNum; i++)
	{
		tmp = max(tmp, purchaseCard(cardNum-i)+cardPackPrice[i]);
	}
	cache[cardNum] = tmp;
	return cache[cardNum];
}

int main()
{
	int cardNum, packPrice;
	cin >> cardNum;
	cardPackPrice = new int(cardNum+1);
	for(int i=1; i<=cardNum; i++)
	{
		cin >> packPrice;
		cardPackPrice[i] = packPrice;
	}
	cout << purchaseCard(cardNum) << endl;
}