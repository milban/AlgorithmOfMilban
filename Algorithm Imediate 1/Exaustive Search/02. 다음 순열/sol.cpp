#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int size;
    scanf("%d", &size);
    vector<int> v;
    for(int i=0; i<size; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    
    if(next_permutation(v.begin(), v.end()))
    {
        for(int i=0; i<size; i++)
            printf("%d ", v[i]);
    }
    else
        printf("-1\n");
    
    return 0;
}