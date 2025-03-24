#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<pair<int, int>> q;
    int index = 0;
    int currentWeight = 0;
    int currentTime = 0;
    do
    {
        if (currentTime - q.front().first == bridge_length)
        {
            currentWeight -= q.front().second;
            q.pop();
        }

        if (index != truck_weights.size() && truck_weights[index] + currentWeight <= weight)
        {
            q.push(make_pair(currentTime, truck_weights[index]));
            currentWeight += truck_weights[index];
            index++;
        }

        currentTime++;
    } while (!q.empty());

    return currentTime;
}