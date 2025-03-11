#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    multiset<int> BTeam(B.begin(), B.end());
    for (int a : A)
    {
        auto iter = BTeam.upper_bound(a);
        if (iter != BTeam.end())
        {
            BTeam.erase(iter);
            answer++;
        }
    }

    return answer;
}