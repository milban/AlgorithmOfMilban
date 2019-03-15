#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student
{
  public:
    int scoreKorean;
    int scoreEng;
    int scoreMath;
    string name;
    Student(string _name, int _scoreKorean, int _scoreEng, int _scoreMath)
    {
        name = _name;
        scoreKorean = _scoreKorean;
        scoreEng = _scoreEng;
        scoreMath = _scoreMath;
    }
};

bool compare(const Student &a, const Student &b)
{
    if (a.scoreKorean == b.scoreKorean && a.scoreEng == b.scoreEng && a.scoreMath == b.scoreMath)
        return a.name < b.name;
    else if (a.scoreKorean == b.scoreKorean && a.scoreEng == b.scoreEng)
        return a.scoreMath > b.scoreMath;
    else if (a.scoreKorean == b.scoreKorean)
        return a.scoreEng < b.scoreEng;
    else
    {
        return a.scoreKorean > b.scoreKorean;
    }
}

int main()
{
    int inputCnt;
    scanf("%d", &inputCnt);
    vector<Student> v;
    for (int i = 0; i < inputCnt; i++)
    {
        string tmpName;
        int tmpKoScore, tmpEngScore, tmpMathScore;
        cin >> tmpName >> tmpKoScore >> tmpEngScore >> tmpMathScore;
        v.push_back(Student(tmpName, tmpKoScore, tmpEngScore, tmpMathScore));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < inputCnt; i++)
    {
        printf("%s\n", v[i].name.c_str());
    }
    return 0;
}