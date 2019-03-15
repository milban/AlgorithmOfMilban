#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

class XY{
public:
    int x;
    int y;
    XY(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

bool compare(const XY &a, const XY &b)
{
    if(a.y == b.y)
        return a.x < b.x;
    else
    {
        return a.y < b.y;
    }
}

int main()
{
    int inputCnt;
    scanf("%d", &inputCnt);
    vector<XY> v;
    for(int i=0; i<inputCnt; i++)
    {
        int tmpX, tmpY;
        scanf("%d %d", &tmpX, &tmpY);
        v.push_back(XY(tmpX, tmpY));
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<inputCnt; i++)
    {
        printf("%d %d\n", v[i].x, v[i].y);
    }
    return 0;
}