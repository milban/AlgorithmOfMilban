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
    int testN;
    scanf("%d", &testN);
    for(int i=0; i<testN; i++)
    {
        int size;
        scanf("%d", &size);
        int *tmpArr = new int[size];
        for(int j=0; j<size; j++)
            scanf("%d", &tmpArr[j]);
        vector<int> *graph = new vector<int>[size+1];
        for(int j=1; j<size+1; j++)
        {
            graph[j].push_back(tmpArr[j-1]);
        }
        bool isVisit[size+1];
        fill(isVisit, isVisit+size+1, false);
        int cnt = 0;
        for(int j=1; j<size+1; j++)
        {
            if(!isVisit[j])
            {
                dfs(graph, isVisit, j);
                cnt++;
            }
        }
        printf("%d\n", cnt);
        delete[] tmpArr;
        delete[] graph;
    }
    return 0;
}