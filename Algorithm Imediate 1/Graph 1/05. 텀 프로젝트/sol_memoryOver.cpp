#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<int> *graph, bool isVisit[], int curNode, int startNode, int depth)
{
    if(isVisit[curNode])
        return false;
    if (curNode == startNode && depth != 0)
        return true;
    int nextNode = graph[curNode][0];
	if(curNode == nextNode)
	{
		if(depth == 0)
		{
			isVisit[curNode] = true;
			return true;
		}
		else
			return false;
	}
    bool isCircle = dfs(graph, isVisit, nextNode, startNode, depth + 1);
    if (isCircle)
        isVisit[curNode] = true;
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

        for(int j=1; j<size+1; j++)
        {
            dfs(graph, isVisit, j, j, 0);
        }

        int cnt = 0;
        for(int j=1; j<size+1; j++)
        {
            if(!isVisit[j])
                cnt++;
        }

        printf("%d\n", cnt);

        delete[] tmpArr;
        delete[] graph;
    }
    return 0;
}