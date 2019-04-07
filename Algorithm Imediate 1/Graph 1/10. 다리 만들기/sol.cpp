#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

#define maxSize 100

int map[maxSize][maxSize];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int continentName = 1;
vector<vector<pair<int, int>>> continentXY;

void distinguishCntinent(int startX, int startY, int size)
{
    pair<int, int> start = make_pair(startX, startY);
    queue<pair<int, int>> q;
    q.push(start);
    map[start.first][start.second] = continentName;
    vector<pair<int, int>> continent;
    continent.push_back(start);

    while(!q.empty())
    {
        pair<int, int> qFront = q.front();
        q.pop();
        int x = qFront.first, y = qFront.second;

        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || ny<0 || nx>= size || ny>=size) continue;
            if(map[nx][ny] != 1) continue;
            map[nx][ny] = continentName;
            continent.push_back(make_pair(nx, ny));
            q.push(make_pair(nx, ny));
        }
    }
    continentXY.push_back(continent);
}

int calMinBridgeLen()
{
    int result = 99999;
    for(int i=0; i<continentXY.size(); i++)
    {
        for(int j=i+1; j<continentXY.size(); j++)
        {
            for(int k=0; k<continentXY[i].size(); k++)
            {
                int x1 = continentXY[i][k].first;
                int y1 = continentXY[i][k].second;
                for(int m=0; m<continentXY[j].size(); m++)
                {
                    int x2 = continentXY[j][m].first;
                    int y2 = continentXY[j][m].second;
                    int len = abs(x1-x2) + abs(y1-y2);
                    result = min(result, len);
                }
            }
        }
    }
    return result-1;
}

int main()
{
    int size;
    scanf("%d", &size);
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            scanf("%d", &map[i][j]);
    }

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(map[i][j] == 1)
            {
                continentName++;
                distinguishCntinent(i, j, size);
            }
        }
    }
    printf("%d", calMinBridgeLen());
    return 0;
}