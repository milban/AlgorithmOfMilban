#include <iostream>
using namespace std;

int result = 1000000;

void makeNumToOne(int num, int operCnt)
{
    if(num == 1)
    {
        if(result > operCnt)
            result = operCnt;
        return;
    }
		if(result <= operCnt) // 지금 저장된 결과(연산 회수)가 현재 연산 회수보다 적을때 재귀 종료
				return;
    if(num%2==0)
        makeNumToOne(num/2, operCnt+1);
    if(num%3==0)
	    	makeNumToOne(num/3, operCnt+1);
		makeNumToOne(num-1, operCnt+1);
	return;
}

int main()
{
    int input;
    cin >> input;
    makeNumToOne(input, 0);
    cout << result << endl;
    return 0;
}