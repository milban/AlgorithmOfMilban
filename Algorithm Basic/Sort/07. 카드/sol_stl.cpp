#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

class Card{
public:
    long long cardNum;
    int cnt;
    Card(long long cn, int tmpCnt)
    {
        cardNum = cn;
        cnt = tmpCnt;
    }
};

bool compare(Card a, Card b)
{
    if(a.cnt == b.cnt)
        return a.cardNum < b.cardNum;
    else
    {
        return a.cnt > b.cnt;
    }
    
}

int main()
{
    int cardCnt;
    scanf("%d", &cardCnt);
    vector<long long> v;
    for(int i=0; i<cardCnt; i++)
    {
        long long cardNum;
        scanf("%lld", &cardNum);
        v.push_back(cardNum);
    }
    sort(v.begin(), v.end());
	
    vector<Card> vc;
    for(int i=0, cnt =1; i<v.size(); i++, cnt++)
    {
        if(v[i] != v[i+1])
        {
            vc.push_back(Card(v[i], cnt));
            cnt =0;
        }
    }
    sort(vc.begin(), vc.end(), compare);

    printf("%lld", vc[0].cardNum);
    return 0;
}