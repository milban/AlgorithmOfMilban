#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class User
{
  public:
    int registCnt;
    int age;
    string name;
    User(int _registCnt, int _age, string _name)
    {
        registCnt = _registCnt;
        age = _age;
        name = _name;
    }
};

bool compare(const User &a, const User &b)
{
    if (a.age == b.age)
    {
        return a.registCnt < b.registCnt;
    }
    else
    {
        return a.age < b.age;
    }
}

int main()
{
    int inputCnt;
    scanf("%d", &inputCnt);
    vector<User> v;
    for (int i = 0; i < inputCnt; i++)
    {
        int tmpAge;
        string tmpName;
        cin >> tmpAge >> tmpName;
        /*
            scanf로 받기
            char tmpName[100];
            scanf("%d %s", &tmpAge, tmpName);
        */
        v.push_back(User(i, tmpAge, tmpName));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < inputCnt; i++)
    {
        printf("%d %s\n", v[i].age, v[i].name.c_str());
    }
    return 0;
}