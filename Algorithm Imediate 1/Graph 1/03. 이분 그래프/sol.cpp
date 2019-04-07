#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> *graph;
bool *isVisit;
int *colorArr;
int nodeN, edgeN;

void dfs(int curNode, int color)
{
    isVisit[curNode] = true;
    if(colorArr[curNode]==-1)
        colorArr[curNode] = color;

    for(int i=0; i<graph[curNode].size(); i++)
    {
        int nextNode = graph[curNode][i];
        if(!isVisit[nextNode])
        {
            dfs(nextNode, !colorArr[curNode]);
        }
    }
}

bool isBipartiteGraph()
{
    bool isBG = true;

    for(int i=1; i<nodeN+1; i++)
    {
        dfs(i, 1);
    }

    for(int i=1; i<nodeN+1; i++)
    {
        int curColor = colorArr[i];
        for(int j=0; j<graph[i].size(); j++)
        {
            int connectColor = colorArr[graph[i][j]];
            if(curColor==connectColor)
            {
                isBG = false;
                break;
            }
        }
        if(!isBG)
            break;
    }
    return isBG;
}

int main()
{
    int testN;
    scanf("%d", &testN);
    for(int i=0; i<testN; i++)
    {
        scanf("%d %d", &nodeN, &edgeN);
        graph = new vector<int>[nodeN+1];
        isVisit = new bool[nodeN+1];
        colorArr = new int[nodeN+1];

        fill(isVisit, isVisit+nodeN+1, false);
        fill(colorArr, colorArr+nodeN+1, -1);
        for(int j=0; j<edgeN; j++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool isBG = isBipartiteGraph();
        if(isBG)
            printf("YES\n");
        else
            printf("NO\n");
    }

    
    return 0;
}