#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
    1. end time 오름차순 소팅
    2. 첫 번째 선택
    3. 첫 번째 end time보다 빠른 first time을 가진 원소 제거
    4. 1부터 반복
*/

bool compareEndTime(pair<int, int> A, pair<int, int> B)
{
    return A.second < B.second;
}

int calMaxMeetingCnt(vector<pair<int, int>> v_meeting, int endTime, int cnt)
{
    if(v_meeting.empty())
        return cnt;
        
    sort(v_meeting.begin(), v_meeting.end(), compareEndTime);
    int _endTime = v_meeting[0].second;
	//printf("_endTime: %d\n", _endTime);
    vector<pair<int, int>>::iterator it = v_meeting.begin();
    while(it!=v_meeting.end())
    {
        if(it->first < _endTime)
            it = v_meeting.erase(it);
        else
            it++;
    }
    int result = calMaxMeetingCnt(v_meeting, _endTime, cnt+1);
	return result;
}

void printVector(vector<pair<int, int>> v)
{
    for(int i=0; i<v.size(); i++)
        printf("%d %d\n", v[i].first, v[i].second);
}

int main()
{
    int meetingCnt;
    scanf("%d", &meetingCnt);
    vector<pair<int, int>> v_meeting;
    for(int i=0; i<meetingCnt; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        v_meeting.push_back(make_pair(start, end));
    }

    int maxMeetingCnt = calMaxMeetingCnt(v_meeting, 0, 0);
    printf("%d\n", maxMeetingCnt);
    return 0;
}