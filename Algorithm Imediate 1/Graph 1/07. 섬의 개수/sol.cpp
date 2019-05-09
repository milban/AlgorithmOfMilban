#include <stdio.h>

using namespace std;

#define size 50

int w, h;
int map[size][size];
int cnt = 0;
int isVisit[size][size];

void initVisit()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            isVisit[i][j] = false;
    }
}

void cntIsland(int i, int j)
{
    if (isVisit[i][j])
        return;
    isVisit[i][j] = true;
    if (map[i][j] == 0)
        return;

    cnt++;
    if (i - 1 >= 0 && !isVisit[i - 1][j]) // 위쪽
        cntIsland(i - 1, j);
    if (i + 1 < h && !isVisit[i + 1][j]) // 아래쪽
        cntIsland(i + 1, j);
    if (j + 1 < w && !isVisit[i][j + 1]) // 오른쪽
        cntIsland(i, j + 1);
    if (j - 1 >= 0 && !isVisit[i][j - 1]) // 왼쪽
        cntIsland(i, j - 1);
    if (i + 1 < h && j + 1 < w && !isVisit[i + 1][j + 1]) // 우하단
        cntIsland(i + 1, j + 1);
    if (i + 1 < h && j - 1 >= 0 && !isVisit[i + 1][j - 1]) // 좌하단
        cntIsland(i + 1, j - 1);
    if (i - 1 >= 0 && j + 1 < w && !isVisit[i - 1][j + 1]) // 우상단
        cntIsland(i - 1, j + 1);
    if (i - 1 >= 0 && j - 1 >= 0 && !isVisit[i - 1][j - 1]) // 좌상단
        cntIsland(i - 1, j - 1);
}

int main()
{
    while (true)
    {
        scanf("%d %d", &w, &h);
        if (w == 0, h == 0)
            break;

        initVisit();

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
        int result = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cnt = 0;
                cntIsland(i, j);
                if (cnt > 0)
                    result++;
            }
        }
        printf("%d\n", result);
    }

    return 0;
}