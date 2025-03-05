#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    priority_queue<int> pq(works.begin(), works.end());
    for (int i = 0; i < n; i++)
    {
        int n = pq.top();
        if (n != 0)
        {
            pq.pop();
            pq.push(--n);
        }
    }

    long long answer = 0;
    while (!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}