#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int inputCnt;
    scanf("%d", &inputCnt);
    int* arr = new int[inputCnt];
    for(int i=0; i<inputCnt; i++)
    {
        scanf("%d", arr[i]);
    }

    // 배열 복사
    int* cpyArr = new int[inputCnt];
    for(int i=0; i<inputCnt; i++)
    {
        cpyArr[i] = arr[i];
    }
    sort(cpyArr, cpyArr+inputCnt);
    int minimum = cpyArr[0];
    return 0;
}