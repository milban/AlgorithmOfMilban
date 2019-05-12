#include <iostream>

using namespace std;

int main()
{
    int womanN, manN, internN;
    cin >> womanN >> manN >> internN;
    int maxTeamPeopleN = womanN + manN - internN;
    int teamPeopleN = 0;
    while(teamPeopleN <= maxTeamPeopleN-3 && womanN-2>=0 && manN>0)
    {
        womanN -= 2;
        manN -= 1;
        teamPeopleN += 3;
    }
    int teamN = teamPeopleN/3;
    cout << teamN << endl;
    return 0;
}