#include <iostream>

using namespace std;

int main()
{
    int colLen, rowLen; // row 가로(행) col 세로(열)
    cin >> colLen >> rowLen;
    if(rowLen>colLen)
    {
        int tmp = colLen;
        colLen = rowLen;
        rowLen = tmp;
    }

    colLen -= 1; rowLen -= 1; // 병든 나이트가 1,1에 있기 때문에
    int visitNum = 1;

    int verticalMoveNum = colLen/2;
    
    return 0;
}