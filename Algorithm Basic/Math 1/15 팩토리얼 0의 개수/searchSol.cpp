// 메모리 1984 KB, 시간 0 ms
#include <iostream>
using namespace std;

int main()
{
	int input;
	int five = 0;
	cin >> input;
	for (int i = 5; i <= input; i *= 5){
		five += input / i;
	}
	cout << five << endl;
	return 0;
}