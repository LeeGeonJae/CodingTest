#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works)
{
    sort(works.rbegin(), works.rend());
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (works[index] > 0)
            works[index]--;

        if (index + 1 != works.size())
            index += works[index] < works[index + 1] ? 1 : 0;

        index = works[index] < works[0] ? 0 : index;
    }

    long long answer = 0;
    for (int i = 0; i < works.size(); i++)
        answer += works[i] * works[i];

    return answer;
}