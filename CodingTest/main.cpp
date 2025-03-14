#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    vector<int> board(n + 2);
    sort(lost.begin(), lost.end());
    n -= lost.size();
    for (int i = 0; i < reserve.size(); i++)
    {
        auto iter = find(lost.begin(), lost.end(), reserve[i]);
        if (iter != lost.end())
        {
            *iter = -1;
            n++;
        }
        else
            board[reserve[i]] = 1;
    }

    for (int i = 0; i < lost.size(); i++)
    {
        if (lost[i] == -1)
            continue;

        n++;
        if (board[lost[i] - 1])
            board[lost[i] - 1] = 0;
        else if (board[lost[i] + 1])
            board[lost[i] + 1] = 0;
        else
            n--;
    }

    return n;
}