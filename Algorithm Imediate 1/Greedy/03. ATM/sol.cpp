#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int peopleCnt;
    vector<int> time;
    scanf("%d", &peopleCnt);
    for(int i=0; i<peopleCnt; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        time.push_back(tmp);
    }
    sort(time.begin(), time.end());
    int result = 0;
    for(int _timeIdx=0, multipleCnt=peopleCnt; _timeIdx<peopleCnt; _timeIdx++, multipleCnt--)
    {
        int tmp = time[_timeIdx]*multipleCnt;
        result += tmp;
    }
    printf("%d\n", result);
    return 0;
}