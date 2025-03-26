#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights)
{
    sort(weights.begin(), weights.end());

    unordered_map<int, int> weightBoard;
    vector<int> checkWeight(1001);
    long long answer = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        answer += weightBoard[weights[i] * 2];
        answer += weightBoard[weights[i] * 3];
        answer += weightBoard[weights[i] * 4];
        answer -= checkWeight[weights[i]] * 2;

        weightBoard[weights[i] * 2]++;
        weightBoard[weights[i] * 3]++;
        weightBoard[weights[i] * 4]++;
        checkWeight[weights[i]]++;
    }

    return answer;
}