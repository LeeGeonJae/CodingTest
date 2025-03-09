#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    vector<int> skillCheck(26);
    for (int i = 0; i < skill.size(); i++)
        skillCheck[skill[i] - 'A'] = 1;

    int answer = 0;
    for (string& s : skill_trees)
    {
        int index = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (skillCheck[s[j] - 'A'] && skill[index] != s[j])
            {
                answer--;
                break;
            }
            else if (skillCheck[s[j] - 'A'])
                index += index + 1 == skill.size() ? 0 : 1;
        }
        answer++;
    }

    return answer;
}