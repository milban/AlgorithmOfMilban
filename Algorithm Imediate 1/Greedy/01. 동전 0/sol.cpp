#include <stdio.h>

using namespace std;

int maxCoinIdxLessThanRemainMoney(int *coinArr, int arrSize, int remainMoney)
{
    int idx=arrSize;
    for(int i=arrSize-1; coinArr[i]>remainMoney && i>=0; i--)
        idx = i;
	return idx-1;
}

int calMinCoinCnt(int *coinArr, int arrSize, int moneySum)
{
    int cnt = 0;
    int coin = 100000001;
    while(moneySum!=0)
    {
        if(moneySum<0)
            return -1;
        if(coin > moneySum)
        {
            int maxCoinIdx = maxCoinIdxLessThanRemainMoney(coinArr, arrSize, moneySum);
            coin = coinArr[maxCoinIdx];
        }
        int howManyPlus = moneySum/coin;
        moneySum -= coin*howManyPlus;
        cnt += howManyPlus;
    }
    return cnt;
}

int main()
{
    int coinCnt, moneySum;
    scanf("%d %d", &coinCnt, &moneySum);
    int *coinArr = new int[coinCnt];
    for(int i=0; i<coinCnt; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        coinArr[i] = tmp;
    }
    int result = calMinCoinCnt(coinArr, coinCnt, moneySum);
    printf("%d\n", result);
    return 0;
}