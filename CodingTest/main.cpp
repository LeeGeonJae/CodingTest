#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> completionMap;
    for (int i = 0; i < completion.size(); i++)
        completionMap[completion[i]]++;

    string answer;
    for (string& s : participant)
    {
        if (!completionMap[s])
        {
            answer = s;
            break;
        }
        else
            completionMap[s]--;
    }
    return answer;
}