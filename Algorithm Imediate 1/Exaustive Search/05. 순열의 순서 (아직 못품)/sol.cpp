#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int factorial(int num)
{
    int result = 1;
    for(int i=1; i<=num; i++)
		result = result * i;
    return result;
}

int prob2(queue<int> q)
{
    int result = 0;
    int howManyMinus[21] = {0,};
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
        if(!howManyMinus[num])
            howManyMinus[num]=1;
        int minus = 0;
        for(int i=1; i<=num; i++)
            minus += howManyMinus[i];
        result += (num-minus)*factorial(q.size());
    }
    return result;
}

int main()
{
    int size;
    scanf("%d", &size);
    int proCtgr, nst;
    vector<int> v, toFindV;
    scanf("%d", &proCtgr);

    if(proCtgr == 2)
    {
        queue<int> q;
        for(int i=0; i<size; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            q.push(tmp);
        }
        int result = prob2(q);
        printf("%d\n", result+1);
    }

    return 0;
}