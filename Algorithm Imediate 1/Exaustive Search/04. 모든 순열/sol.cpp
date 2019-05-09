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
        v.push_back(i+1);

    do
    {
        for(int i=0; i<v.size(); i++)
            printf("%d ", v[i]);
        printf("\n");
    } while (next_permutation(v.begin(), v.end()));
    
    return 0;
}