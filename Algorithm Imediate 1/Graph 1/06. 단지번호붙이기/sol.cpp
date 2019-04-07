#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

#define maxSize 25

int map[maxSize][maxSize];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int continentName = 1;
vector<int> apart;

void distinguishApart(int startX, int startY, int size)
{
    pair<int, int> start = make_pair(startX, startY);
    queue<pair<int, int>> q;
    q.push(start);
    map[start.first][start.second] = continentName;
    int cnt = 1;

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
            cnt++;
            q.push(make_pair(nx, ny));
        }
    }
    apart.push_back(cnt);
}

int main()
{
    int arrSize;
    cin >> arrSize;
    for(int i=0; i<arrSize; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j=0; j<arrSize; j++)
            map[i][j] = tmp[j] - '0';
    }

    for(int i=0; i<arrSize; i++)
    {
        for(int j=0; j<arrSize; j++)
        {
            if(map[i][j] == 1)
            {
                continentName++;
                distinguishApart(i, j, arrSize);
            }
        }
    }

    sort(apart.begin(), apart.end());
    cout << apart.size() << endl;
    for(int i=0; i<apart.size(); i++)
        cout << apart[i] << endl;
    return 0;
}