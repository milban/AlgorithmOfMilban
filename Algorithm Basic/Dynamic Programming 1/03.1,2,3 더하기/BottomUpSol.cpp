#include <iostream>
#include <algorithm>
using namespace std;

int cache[12] = {0,};

void initCache()
{
    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
}

int expressNumFor123(int num)
{
    if(cache[num]!=0)
        return cache[num];
    for(int i=3; i<=num; i++)
    {
        cache[i] = cache[i-3] + cache[i-2] + cache[i-1];
    }
    return cache[num];
}

int main()
{
    int num, caseNum;
    cin >> caseNum;
    initCache();
    for(int i=0; i<caseNum; i++)
    {
        cin >> num;
        cout << expressNumFor123(num) << endl;
    }
    return 0;
}