#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int inputCnt, K;
    scanf("%d %d", &inputCnt, &K);
    int *arr = new int[inputCnt];
    for(int i=0; i<inputCnt; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+inputCnt);
    printf("%d", arr[K-1]);
    return 0;
}