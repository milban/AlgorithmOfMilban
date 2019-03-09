#include <iostream>
#include <vector>
using namespace std; 

int main()
{
    int nCnt2 = 0, nCnt5 =0, mCnt2 = 0, mCnt5 =0, inputN, inputM;

    cin >> inputN >> inputM;

    for(long long i=2; i<inputN; i*=2)
    {
        nCnt2 = nCnt2 + inputN/i;
    }
    for(long long i=5; i<inputN; i*=5)
    {
        nCnt5 = nCnt5 + inputN/i;
    }

    for(long long i=2; i<inputN; i*=2)
    {
        mCnt2 = mCnt2 + inputN/i;
    }
    for(long long i=5; i<inputN; i*=5)
    {
        mCnt5 = mCnt5 + inputN/i;
    }

    int resultCnt2 = nCnt2 - mCnt2, resultCnt5 = nCnt5 - mCnt5;
    int result = (resultCnt2 > resultCnt5 ? resultCnt5 : resultCnt2)
    return 0;
}