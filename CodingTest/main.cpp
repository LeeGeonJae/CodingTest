#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 1. 물류 센터는 x, y 좌표가 있다
// 2. 로봇마다 운송 경로가 m개의 포인트로 구성되고 첫 포인트부터 할당된 포인트를 순서대로 방문
// 3. 모든 로봇(m개)은 0초에 동시에 출발하고 1초마다 r좌표와 c좌표 중 하나가 1만큼 이동
// 4. 다음 포인트로 이동 시에 항상 최단 경로로 이동 경우가 여러 가지일 때, r좌표 먼저 이동
// 5. 마지막 포인트에 도착한 로봇은 운송을 마치고 물류 센터를 벗어난다. 벗어나는 경로는 고려x

// 출력 : 같은 좌표에 2대 이상 모일 경우 answer++
// 입력 : 운송 포인트 n개의 좌표를 담은 points
// 입력 : x대의 운송 경로를 담은 routes

// 로봇 시작 위치 : routes[0] 물류 위치
// 로봇 목표 위치 : routes[1], routes[2] ... routes[m] 물류 위치

// y 이동 -> x 이동

class Robot
{
public:
    Robot(vector<vector<int>>& points, vector<int> route)
        : x(points[route[0] - 1][1])
        , y(points[route[0] - 1][0])
        , targetPosition(1)
        , robotRoute(route)
    {
    }

    void MoveRobot(vector<vector<int>>& points)
    {
        if (IsComplete())
            return;

        int targetX = points[robotRoute[targetPosition] - 1][1];
        int targetY = points[robotRoute[targetPosition] - 1][0];

        if (y != targetY)
            y += targetY > y ? 1 : -1;
        else if (x != targetX)
            x += targetX > x ? 1 : -1;

        if (x == targetX && y == targetY)
            targetPosition++;
    }

    bool IsComplete()
    {
        if (targetPosition >= robotRoute.size())
            return true;
        return false;
    }

    string GetPosition()
    {
        string s = "y : " + to_string(y) + ", x : " + to_string(x);
        return s;
    }

private:
    int x;
    int y;
    int targetPosition;

    vector<int> robotRoute;
};

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    vector<Robot> robots;
    vector<int> startPointBoard = vector<int>(101, 0);
    for (int i = 0; i < routes.size(); i++)
    {
        startPointBoard[routes[i][0]]++;
        Robot robot(points, routes[i]);
        robots.push_back(robot);
    }

    // 첫 위치 충돌 체크
    int answer = 0;
    for (auto& point : startPointBoard)
        if (point > 1)
            answer++;

    bool isComplete = false;
    while (!isComplete)
    {
        isComplete = true;
        unordered_map<string, int> robotBoard;
        for (auto& robot : robots)
        {
            if (robot.IsComplete() == false)
            {
                robot.MoveRobot(points);
                isComplete = false;
                robotBoard[robot.GetPosition()]++;
            }
        }

        for (auto pos : robotBoard)
            if (pos.second > 1)
                answer++;
    }

    return answer;
}