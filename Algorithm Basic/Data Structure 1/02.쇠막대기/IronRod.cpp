// 메모리 : 2236KB, 시간 : 4ms
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int piece =0;
	stack<int> st;
	string input;
	cin >> input;
	char immediateInput;
	
	for(int i=0; i<input.size(); i++)
	{
		if(input[i] == '(')
		{
			st.push(input[i]);
		}
		else if(input[i] == ')')
		{
			if(immediateInput == '(')
			{
				st.pop();
				piece += st.size();
			}
			else
			{
				piece++;;
				st.pop();
			}
		}
		immediateInput = input[i];
	}
	cout << piece << endl;
	return 0;
}