#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define maxSize 100

int map[maxSize][maxSize];
bool isVisit[maxSize][maxSize];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int h, w;

struct Node
{
    int x;
    int y;
    int depth;
};

void initIsVisit()
{
    for(int i=0; i<maxSize; i++)
    {
        for(int j=0; j<maxSize; j++)
            isVisit[i][j] = false;
    }
}

int bfs()
{
    queue<Node> q;
    Node start;
    start.x = 0;
    start.y = 0;
    start.depth =1;
    isVisit[0][0] = true;
    q.push(start);

    while(!q.empty())
    {
        Node qFront = q.front();
        q.pop();
        int x = qFront.x;
        int y = qFront.y;
        int depth = qFront.depth;
        if(x==h-1 && y==w-1)
            return depth;
        
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
            if(isVisit[nx][ny] || !map[nx][ny]) continue;
            isVisit[nx][ny] = true;
            Node tmp;
            tmp.x = nx;
            tmp.y = ny;
            tmp.depth = depth+1;
            q.push(tmp);
        }
    }
}

int main()
{
    initIsVisit();
    cin >> h >> w;
    for(int i=0; i<h; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j=0; j<w; j++)
        {
            map[i][j] = tmp[j] - '0';
        }
    }
    int result = bfs();
    cout << result << endl;
    return 0;
}