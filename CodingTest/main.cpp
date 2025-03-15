#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y)
{
    vector<int> number(10);
    for (auto& c : X)
        number[c - '0']++;

    string answer = "";
    for (int i = 0; i < Y.size(); i++)
    {
        if (number[Y[i] - '0'])
        {
            answer += Y[i];
            number[Y[i] - '0']--;
        }
    }

    sort(answer.rbegin(), answer.rend());
    return answer.empty() ? "-1" : answer[0] == '0' ? "0" : answer;
}