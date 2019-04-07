#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define maxSize 1000

int map[maxSize][maxSize];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<pair<int, int>> startPoint;

struct Node
{
    int x;
    int y;
    int depth;
};

bool isAllRipe(int h, int w)
{
    bool result = true;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int state = map[i][j];
            if (state == 0)
                result = false;
            if (state == 1)
                startPoint.push_back(make_pair(i, j));
        }
    }

    return result;
}

int bfs(int h, int w)
{
    if (isAllRipe(h, w))
        return 0;
    int result;
    queue<Node> q;
    for (int n = 0; n < startPoint.size(); n++)
    {
        Node start;
        start.x = startPoint[n].first;
        start.y = startPoint[n].second;
        start.depth = 0;
        q.push(start);
    }

    while (!q.empty())
    {
        Node qFront = q.front();
        q.pop();
        int x = qFront.x, y = qFront.y, depth = qFront.depth;
        result = depth;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                continue;
            if (map[nx][ny] || map[nx][ny] == -1)
                continue;
            map[nx][ny] = true;
            Node tmp;
            tmp.x = nx;
            tmp.y = ny;
            tmp.depth = depth + 1;
            q.push(tmp);
        }
    }
    return result;
}

int main()
{
    int h, w;
    scanf("%d %d", &w, &h);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            scanf("%d", &map[i][j]);
    }
    int result = bfs(h, w);
    if(!isAllRipe(h, w))
        printf("-1\n");
    else
        printf("%d", result);
    return 0;
}