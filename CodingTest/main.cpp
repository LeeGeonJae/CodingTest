#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    vector<string> babyLanguage = { "aya", "ye", "woo", "ma" };

    for (auto& s : babbling)
    {
        int sequence = -1;
        while (!s.empty())
        {
            bool isFind = false;
            for (int i = 0; i < babyLanguage.size(); i++)
            {
                auto pos = s.find(babyLanguage[i]);
                if (pos == 0 && sequence != i)
                {
                    sequence = i;
                    isFind = true;
                    s.erase(pos, pos + babyLanguage[i].size());
                    answer += s.empty() ? 1 : 0;
                }
            }

            if (!isFind)
                break;
        }
    }

    return answer;
}