#include <string>
#include <vector>

using namespace std;

enum
{
    Down = 0,
    Right,
    Up,
    End
};

vector<int> solution(int n)
{
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
            triangle[i].push_back(0);

    int index = 0;
    int number = 0;
    int y = 0; int x = 0;
    int direction = Down;
    while (n)
    {
        index++; number++;
        triangle[y][x] = number;

        // 방향 전환
        if (index == n)
        {
            n--;
            index = 0;
            direction = (direction + 1) % End;
        }

        // 좌표 변환
        if (direction == Down)
            y++;
        else if (direction == Right)
            x++;
        else
        {
            y--;
            x--;
        }
    }

    vector<int> answer;
    for (int i = 0; i < triangle.size(); i++)
        for (int j = 0; j < triangle[i].size(); j++)
            answer.push_back(triangle[i][j]);

    return answer;
}