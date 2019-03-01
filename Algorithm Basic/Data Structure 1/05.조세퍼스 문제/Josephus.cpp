// 메모리 1988KB, 시간 : 68ms
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    queue<int> qqq;
    int peopleNum, nst;
    cin >> peopleNum >> nst;
    for (int i = 0; i < peopleNum; i++)
    {
        qqq.push(i + 1);
    }
    cout << "<";
    while (!qqq.empty())
    {
        for (int i = 0; i < nst - 1; i++)
        {
            int tmp = qqq.front();
            qqq.push(tmp);
            qqq.pop();
        }
        cout << qqq.front();
        if (qqq.size() != 1)
            cout << ", ";
        qqq.pop();
    }
    cout << ">" << endl;
    return 0;
}