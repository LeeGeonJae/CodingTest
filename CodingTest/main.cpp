#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void DFS(unordered_map<int, vector<pair<int, int>>>& roadBoard, vector<bool>& visited, vector<pair<int, int>>& delivery, set<int>& answer, int K)
{
    int currentTown = delivery.back().first;
    int currentLength = delivery.back().second;
    for (auto& road : roadBoard[currentTown])
    {
        int nextTown = road.first;
        int nextLength = road.second;
        if (visited[nextTown] || currentLength + nextLength > K)
            continue;

        answer.insert(nextTown);
        visited[nextTown] = true;
        delivery.push_back(make_pair(nextTown, currentLength + nextLength));
        DFS(roadBoard, visited, delivery, answer, K);
        delivery.pop_back();
        visited[nextTown] = false;
    }
}

int solution(int N, vector<vector<int> > road, int K)
{
    unordered_map<int, vector<pair<int, int>>> roadBoard;
    for (vector<int>& vec : road)
    {
        roadBoard[vec[0]].push_back(make_pair(vec[1], vec[2]));
        roadBoard[vec[1]].push_back(make_pair(vec[0], vec[2]));
    }

    set<int> answer;
    vector<bool> checkBoard(N + 1);
    vector<pair<int, int>> delivery;
    delivery.push_back(make_pair(1, 0));
    checkBoard[1] = true;
    answer.insert(1);
    DFS(roadBoard, checkBoard, delivery, answer, K);

    return answer.size();
}