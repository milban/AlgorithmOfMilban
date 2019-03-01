// 메모리 : 1992KB, 시간 : 4ms
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void pirntIsVPS(string _input)
{
	stack<int> st;
	for (int j = 0; j < _input.size(); j++)
	{
		if (_input[j] == '(')
		{
			st.push(_input[j]);
		}
		else
		{
			if (st.size() == 0)
			{
				cout << "NO" << endl;
				return;
			}
			else
			{
				st.pop();
			}
		}
	}
	if (st.size() > 0)
		cout << "NO" << endl;
	else if (st.empty())
		cout << "YES" << endl;
}

int main()
{
	int cnt;
	cin >> cnt;
	string input;

	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		pirntIsVPS(input);
	}
	return 0;
}