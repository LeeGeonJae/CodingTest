#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& computers, vector<bool>& check, int num)
{
    for (int i = 0; i < computers[num].size(); i++)
    {
        if (computers[num][i] == 1
            && check[i] == false)
        {
            check[i] = true;
            DFS(computers, check, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> check = vector<bool>(n, false);

    for (int i = 0; i < computers.size(); i++)
    {
        if (check[i] == false)
        {
            answer++;
            check[i] = true;
            DFS(computers, check, i);
        }
    }

    return answer;
}