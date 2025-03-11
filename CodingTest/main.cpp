#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n)
{
    int answer = -1;
    queue<pair<int, int>> q;
    vector<bool> checkBoard(1000001);
    q.push(make_pair(0, x));
    while (!q.empty())
    {
        int number = q.front().second;
        int cnt = q.front().first;
        if (number * 2 <= y && !checkBoard[number * 2])
        {
            q.push(make_pair(cnt + 1, number * 2));
            checkBoard[number * 2] = true;
        }
        if (number * 3 <= y && !checkBoard[number * 3])
        {
            q.push(make_pair(cnt + 1, number * 3));
            checkBoard[number * 3] = true;
        }
        if (number + n <= y && !checkBoard[number + n])
        {
            q.push(make_pair(cnt + 1, number + n));
            checkBoard[number + n] = true;
        }

        if (q.front().second == y)
        {
            answer = cnt;
            break;
        }

        q.pop();
    }

    return answer;
}