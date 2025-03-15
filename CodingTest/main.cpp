#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int point = -30001;
    sort(routes.begin(), routes.end(), [](vector<int>& lhs, vector<int>& rhs)
        {
            return lhs[1] < rhs[1];
        });

    int answer = 0;
    for (int i = 0; i < routes.size(); i++)
    {
        if (point < routes[i][0])
        {
            point = routes[i][1];
            answer++;
        }
    }

    return answer;
}