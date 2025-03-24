#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    queue<int> q1;
    queue<int> q2;
    long long lhs = 0;
    long long rhs = 0;
    for (int& n : queue1)
    {
        q1.push(n);
        lhs += n;
    }
    for (int& n : queue2)
    {
        q2.push(n);
        rhs += n;
    }

    if ((lhs + rhs) % 2)
        return -1;

    int answer = 0;
    while (lhs != rhs)
    {
        if (lhs < rhs)
        {
            q1.push(q2.front());
            lhs += q2.front();
            rhs -= q2.front();
            q2.pop();
        }
        else if (rhs < lhs)
        {
            q2.push(q1.front());
            rhs += q1.front();
            lhs -= q1.front();
            q1.pop();
        }
        answer++;

        if (answer > (queue1.size() + queue2.size()) * 2)
            return -1;
    }

    return answer;
}