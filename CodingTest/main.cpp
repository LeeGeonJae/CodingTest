#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k)
{
    int answer = 0;
    queue<pair<int, int>> server;
    int currentTime = 0;
    int serverCnt = 0;
    for (int& n : players)
    {
        currentTime++;
        if (!server.empty() && currentTime - server.front().first >= k)
        {
            serverCnt -= server.front().second;
            server.pop();
        }

        int serverAdd = n / m - serverCnt;
        if (serverAdd > 0)
        {
            server.push(make_pair(currentTime, serverAdd));
            serverCnt += serverAdd;
            answer += serverAdd;
        }
    }

    return answer;
}