// 메모리 : 1988KB, 시간 : 344ms
#include <iostream>
#include <string>
using namespace std;

class que
{
  private:
    int index_front, index_back;
    int *arr;

  public:
    que(int num)
    {
        index_front = -1;
        index_back = 0;
        arr = new int[num];
    }
    void push(int item)
    {
        if (index_front == -1)
        {
            arr[++index_front] = item;
        }
        else
        {
            arr[++index_back] = item;
        }
    }
    int pop()
    {
        if (index_front == -1)
            return -1;
        else
        {
            if (index_front == index_back)
            {
                index_front = -1;
                int tmp = arr[index_back];
                index_back = 0;
                return tmp;
            }
            else
            {
                return arr[index_front++];
            }
        }
    }
    int size()
    {
        if (index_front == -1)
            return 0;
        else
        {
            return index_back - index_front + 1;
        }
    }
    int empty()
    {
        if (index_front == -1)
            return 1;
        else
        {
            return 0;
        }
    }
    int front()
    {
        if (empty())
            return -1;
        else
        {
            return arr[index_front];
        }
    }
    int back()
    {
        if (empty())
            return -1;
        else
        {
            return arr[index_back];
        }
    }
};

void printResult(int result)
{
    cout << result << endl;
}

int main()
{
    int cnt;
    string command;
    int item;
    cin >> cnt;
    que qqq(cnt);
    for (int i = 0; i < cnt; i++)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> item;
            qqq.push(item);
        }
        else if (command == "pop")
            printResult(qqq.pop());
        else if (command == "size")
            printResult(qqq.size());
        else if (command == "empty")
            printResult(qqq.empty());
        else if (command == "front")
            printResult(qqq.front());
        else if (command == "back")
            printResult(qqq.back());
    }
    return 0;
}