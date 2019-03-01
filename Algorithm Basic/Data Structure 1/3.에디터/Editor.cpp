// 메모리 : 20844KB, 시간 : 180ms
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    string input, command;
    int cnt;
    list<char> li;
    char inputChar;

    cin >> input >> cnt;

    for (int i = 0; i < input.size(); i++)
    {
        li.push_back(input[i]);
    }

    list<char>::iterator it = li.end();
    for (int i = 0; i < cnt; i++)
    {
        cin >> command;
        if (command == "P")
        {
            cin >> inputChar;
            li.insert(it, inputChar);
        }
        else if (command == "L")
        {
            if (it != li.begin())
                it--;
        }
        else if (command == "D")
        {
            if (it != li.end())
                it++;
        }
        else if (command == "B")
        {
            if (it != li.begin())
            {
                it--;
                it = li.erase(it);
            }
        }
    }

    it = li.begin();
    while (it != li.end())
    {
        cout << *it;
        it++;
    }
    return 0;
}