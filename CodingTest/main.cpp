#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> board(100001);
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' < 10 && s[i] - '0' >= 0)
        {
            temp += s[i];
        }
        else if (temp.size())
        {
            board[stoi(temp)]++;
            temp.clear();
        }
    }

    vector<pair<int, int>> elements;
    for (int i = 0; i < board.size(); i++)
        if (board[i] != 0)
            elements.push_back(make_pair(i, board[i]));

    sort(elements.begin(), elements.end(), [](auto& lhs, auto& rhs)
        {
            return lhs.second > rhs.second;
        });

    vector<int> answer;
    for (auto& p : elements)
        answer.push_back(p.first);

    return answer;
}