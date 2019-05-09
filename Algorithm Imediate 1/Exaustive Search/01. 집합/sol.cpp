#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

class sol {
private:
    bool itemArr[21] = {0,};
public:
    sol(){}
    void add(int x)
    {
        itemArr[x] = true;
    }
    void remove(int x)
    {
        itemArr[x] = false;
    }
    bool check(int x)
    {
        return itemArr[x];
    }
    void toggle(int x)
    {
        if(itemArr[x])
            itemArr[x] = false;
        else
            itemArr[x] = true;
    }
    void all()
    {
        fill(itemArr, itemArr+21, true);
    }
    void empty()
    {
        fill(itemArr, itemArr+21, false);
    }
};

int main()
{
    int testNum;
    scanf("%d", &testNum);
    string command;
    int x;
    sol s;
    for(int i=0; i<testNum; i++)
    {
        char tmp[6];
        scanf("%6s %d", tmp, &x);
        command = tmp;
        if(command == "add")
            s.add(x);
        else if(command == "remove")
            s.remove(x);
        else if(command == "check")
            printf("%d\n", s.check(x));
        else if(command == "toggle")
            s.toggle(x);
        else if(command == "all")
            s.all();
        else if(command == "empty")
            s.empty();
    }
    return 0;
}