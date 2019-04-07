#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> *graph, bool isVisit[], int curNode)
{
    isVisit[curNode] = true;

    for(int i=0; i<graph[curNode].size(); i++)
    {
        int nextNode = graph[curNode][i];
        if(!isVisit[nextNode])
            dfs(graph, isVisit, nextNode);
    }
}

int main()
{
    int nodeN, edgeN;
    scanf("%d %d", &nodeN, &edgeN);
    vector<int> *graph = new vector<int>[nodeN+1];
    bool *isVisit = new bool[nodeN+1];
    fill(isVisit, isVisit+nodeN+1, false);
    for(int i=0; i<edgeN; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cntContCompnt = 0;
    for(int i=1; i<nodeN+1; i++)
    {
        if(!isVisit[i])
        {
            cntContCompnt++;
            dfs(graph, isVisit, i);
        }
    }
    printf("%d", cntContCompnt);
    return 0;
}