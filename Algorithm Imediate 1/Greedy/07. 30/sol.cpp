#include <iostream>
#include <string>
#include <algorithm>
#include <functional> // to use greater<type>()
using namespace std;

/*
    풀이
    1. 30의 배수여야 하므로 0은 들어가야함.
    2. 모든 숫자를 더해 3의 배수이고 1조건을 만족한다면 30의 배수
    3. 가장 큰 30의 배수여야하니까 내림차순으로 정렬
*/

int main()
{
    string inputNum;
    cin >> inputNum;
    if(inputNum.find('0')==string::npos)
    {// '0'이 없다면
        cout << -1 << endl;
        return 0;
    }
    int sum = 0;
    for(int i=0; i<inputNum.size(); i++)
    {
        int tmp = inputNum[i] - '0';
        sum += tmp;
    }
    if(sum%3==0)
    {
        sort(inputNum.begin(), inputNum.end(), greater<char>());
        cout << inputNum << endl;
    }
    else
    {
        cout << -1  << endl;
    }
    
    return 0;
}