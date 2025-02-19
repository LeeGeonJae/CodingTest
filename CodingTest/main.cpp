#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    for (int i = 0; i < progresses.size(); i++)
    {
        int number = 1;
        int updateDay = (99 - progresses[i]) / speeds[i] + 1;

        for (int j = i + 1; j < progresses.size(); j++)
        {
            int nextCompleteDay = (99 - progresses[j]) / speeds[j] + 1;
            if (updateDay < nextCompleteDay)
                break;

            i = j;
            number++;
        }

        answer.push_back(number);
    }

    return answer;
}