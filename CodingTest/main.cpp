#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <math.h>

using namespace std;

void DFS(stack<string>& q, unordered_map<string, vector<string>>& wordMap
    , unordered_map<string, bool>& checkMap, int& number, string& target)
{
    if (q.top() == target)
    {
        number = number ? (number > q.size() - 1 ? q.size() - 1 : number) : q.size() - 1;
        return;
    }

    for (int i = 0; i < wordMap[q.top()].size(); i++)
    {
        if (!checkMap[wordMap[q.top()][i]] && (number == 0 ? 1 : number > q.size()))
        {
            q.push(wordMap[q.top()][i]);
            checkMap[q.top()] = true;
            DFS(q, wordMap, checkMap, number, target);
            checkMap[q.top()] = false;
            q.pop();
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    unordered_map<string, vector<string>> wordMap;
    unordered_map<string, bool> checkMap;
    checkMap[begin] = false;
    for (auto& s : words)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            num += (begin[i] != s[i]);
            if (num > 1)
                break;
        }
        if (num == 1)
            wordMap[begin].push_back(s);
    }

    for (int i = 0; i < words.size(); i++)
    {
        checkMap[words[i]] = false;
        for (int j = 0; j < words.size(); j++)
        {
            int num = 0;
            for (int k = 0; k < words[i].size(); k++)
            {
                num += (words[i][k] != words[j][k]);
                if (num > 1)
                    break;
            }

            if (num == 1)
                wordMap[words[i]].push_back(words[j]);
        }
    }

    int answer = 0;
    stack<string> q;
    q.push(begin);
    DFS(q, wordMap, checkMap, answer, target);
    return answer;
}