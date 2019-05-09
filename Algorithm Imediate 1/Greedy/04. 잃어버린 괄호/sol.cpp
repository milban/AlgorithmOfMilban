#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string Equation;
    cin >> Equation;
    Equation += '+';
    stack<char> stck;
    char op = '+';
    int result = 0;
    for(int i=0; i<Equation.size(); i++)
    {
        char tmp = Equation[i];
        if(tmp >= '0' && tmp <= '9')
            stck.push(tmp-'0');
        else
        {
            int num = 0;
            int digit = 1;
            while(!stck.empty())
            {
                num += stck.top() * digit;
                stck.pop();
                digit *= 10;
            }
            if(op=='+')
                result += num;
            else
                result -= num;
            if(tmp=='-')
                op = tmp;
        }
    }
    cout << result << endl;
    return 0;
}