// 메모리 : 1988KB, 시간 : 324ms
#include <iostream>
#include <string>
using namespace std;

class Stack
{
  private:
    int index;
    int length;
    int *itemArr;

  public:
    Stack(int size)
    {
        index = 0;  // 가장 마지막에 들어온 item 인덱스
        length = 0; // 스택 사이즈
        itemArr = new int[size];
    }
    void push(int item)
    {
        index = length;
        itemArr[index] = item;
        length++;
    }
    int pop()
    {
        if (length == 0)
            return -1;
        else
        {
            int result = itemArr[index];
            index--;
            length--;
            return result;
        }
    }
    int size()
    {
        return length;
    }
    int empty()
    {
        if (length == 0)
            return 1;
        else
            return 0;
    }
    int top()
    {
        if (length == 0)
            return -1;
        else
            return itemArr[index];
    }
};

void printInt(int a)
{
    cout << a << endl;
}

int main()
{
    int cnt, item;
    string command;
    cin >> cnt;
    Stack myStack(cnt);

    for (int i = 0; i < cnt; i++)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> item;
            myStack.push(item);
        }
        else if (command == "pop")
        {
            printInt(myStack.pop());
        }
        else if (command == "size")
        {
            printInt(myStack.size());
        }
        else if (command == "empty")
        {
            printInt(myStack.empty());
        }
        else if (command == "top")
        {
            printInt(myStack.top());
        }
    }
    return 0;
}