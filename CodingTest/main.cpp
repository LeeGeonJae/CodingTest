#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool checkWord(string& lhs, string& rhs, int num)
{
    int cnt = 0;
    for (int i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i])
        {
            cnt++;
            if (cnt > num)
                break;
        }
    }

    return cnt == 1 ? true : false;
}

int solution(string begin, string target, vector<string> words)
{
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    unordered_map<string, int> board;
    queue<string> q;
    q.push(begin);

    while (!q.empty())
    {
        string currentWord = q.front();
        q.pop();

        if (currentWord == target)
            return board[currentWord];

        for (int i = 0; i < words.size(); i++)
        {
            if (checkWord(currentWord, words[i], 1)
                && board[words[i]] == 0)
            {
                board[words[i]] = board[currentWord] + 1;
                q.push(words[i]);
            }
        }
    }

    return 0;
}