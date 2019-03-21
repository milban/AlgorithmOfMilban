#include <stdio.h>
using namespace std;

int main()
{
    int arr[10001] = {0,};
    int inputCnt;
    scanf("%d", &inputCnt);
    for(int i=0; i<inputCnt; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp]++;
    }
    for(int i=1; i<10001; i++)
    {
        while(arr[i]>0)
        {
            printf("%d\n", i);
            arr[i]--;
        }
    }
    return 0;
}