#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int negativeNumArrMaxSum(vector<int> v)
{
    int result = 0;
    sort(v.begin(), v.end());
    queue<int> q;
    for(int i=0; i<v.size(); i++)
        q.push(v[i]);
    
    while(!q.empty())
    {
        int n_num1, n_num2 = 1;
        n_num1 = q.front();
        q.pop();
        if(!q.empty())
        {// 개수가 홀수개 일 때
            n_num2 = q.front();
            q.pop();
        }
        result += n_num1*n_num2;
    }
    return result;
}

int positiveNumArrMaxSum(vector<int> v)
{
    int result = 0;
    sort(v.begin(), v.end());
    stack<int> stk;
    for(int i=0; i<v.size(); i++)
        stk.push(v[i]);

    while(!stk.empty())
    {
        int n_num1, n_num2;
        n_num1 = stk.top();
        stk.pop();
        if(!stk.empty())
        {// 개수가 홀수개 일 때
            n_num2 = stk.top();
            stk.pop();
        }
		else
		{
			result += n_num1;
			break;
		}
		if(n_num2==1)
			result += n_num1+n_num2;
        else
            result += n_num1*n_num2;
    }
    return result;
}

int main()
{
    int size;
    vector<int> v_positive, v_negative;
    scanf("%d", &size);
    for(int i=0; i<size; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(tmp>0)
            v_positive.push_back(tmp);
        else if(tmp<=0)
            v_negative.push_back(tmp);
    }
	int n_max = negativeNumArrMaxSum(v_negative);
	int p_max = positiveNumArrMaxSum(v_positive);
    int result = n_max + p_max;
    printf("%d\n", result);
    return 0;
}