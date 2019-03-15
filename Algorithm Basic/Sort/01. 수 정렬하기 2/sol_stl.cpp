#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int inputCnt;
    scanf("%d", &inputCnt);
    int *arr = new int[inputCnt];
    for(int i=0; i<inputCnt; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+inputCnt);
    for(int i=0; i<inputCnt; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
