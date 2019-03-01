#include <iostream>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (arr[input[i] - 'a'] == -1)
            arr[input[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i];
        if (i != 25)
            cout << " ";
    }
    cout << endl;
    return 0;
}