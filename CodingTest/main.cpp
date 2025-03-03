#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    unordered_map<int, int> stageMap;

    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] <= N)
            stageMap[stages[i]]++;
    }

    int num = stages.size();
    vector<pair<int, double>> rate;
    for (int i = 1; i <= N; i++)
    {
        rate.push_back(make_pair(i, stageMap[i] ? (num ? (double)stageMap[i] / num : 1) : 0));
        num -= stageMap[i];
    }

    sort(rate.begin(), rate.end(), [](auto& lhs, auto& rhs)
        {
            if (lhs.second == rhs.second)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        });

    vector<int> answer;
    for (auto& r : rate)
        answer.push_back(r.first);

    return answer;
}