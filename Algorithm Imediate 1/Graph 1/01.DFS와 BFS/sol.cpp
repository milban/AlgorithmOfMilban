#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(vector<int> *graph, bool check[], int curNode)
{
    check[curNode] = true;
    cout << curNode << " ";
    for(int i=0; i<graph[curNode].size(); i++)
    {
        int nextNode = graph[curNode][i];
		if(!check[nextNode])
        	dfs(graph, check, nextNode);
    }
}

void bfs(vector<int> *graph, bool check[], int curNode)
{
    queue<int> q;
    q.push(curNode);
    check[curNode] = true;

    while(!q.empty())
    {
        int qFront = q.front();
        q.pop();
        cout << qFront << " ";
        for(int i=0; i<graph[qFront].size(); i++)
        {
            int toQPushNode = graph[qFront][i];
            if(!check[toQPushNode])
            {
                q.push(toQPushNode);
                check[toQPushNode] = true;
            }
        }
    }
}

int main()
{
    int nodeCnt, edgeCnt, startNode;
    cin >> nodeCnt >> edgeCnt >> startNode;

    vector<int> *graph = new vector<int>[nodeCnt+1];
    bool *check = new bool[nodeCnt+1];

    for(int i=0; i< edgeCnt; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
		graph[b].push_back(a);
    }

    for(int i=1; i<nodeCnt+1; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    fill(check, check+nodeCnt+1, false);
    dfs(graph, check, startNode);
    cout << endl;
    fill(check, check+nodeCnt+1, false);
    bfs(graph, check, startNode);
    cout << endl;
    return 0;
}