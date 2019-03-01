#include <iostream>
#include <string>
using namespace std;

void printResult(string input)
{
    int arr[4] = {
        0,
    };
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
            arr[0]++;
        else if (input[i] >= 'A' && input[i] <= 'Z')
            arr[1]++;
        else if (input[i] >= '0' && input[i] <= '9')
            arr[2]++;
        else if (input[i] == ' ')
            arr[3]++;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i];
        if (i != 4)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    string input;
    while (getline(cin, input))
    {
        printResult(input);
    }
    return 0;
}