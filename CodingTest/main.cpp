#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    for (int i = 0; i < targets.size(); i++)
    {
        int num = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            int minNumber = 0;
            for (int k = 0; k < keymap.size(); k++)
            {
                auto iter = find(keymap[k].begin(), keymap[k].end(), targets[i][j]);
                if (iter != keymap[k].end())
                    minNumber = minNumber ? min(minNumber, (int)(iter - keymap[k].begin()) + 1) : iter - keymap[k].begin() + 1;
            }

            num = minNumber ? num + minNumber : -1;
            if (!minNumber)
                break;
        }
        answer.push_back(num);
    }

    return answer;
}