#include <string>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<bool>& visited, stack<int>& st, const vector<vector<int>>& computers)
{
    for (int i = 0; i < computers[st.top()].size(); i++)
    {
        if (!visited[i] && computers[st.top()][i])
        {
            visited[i] = true;
            st.push(i);
            DFS(visited, st, computers);
            st.pop();
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int network = 0;
    vector<bool> visited(computers.size(), false);
    stack<int> st;

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i])
            continue;

        network++;
        st.push(i);
        DFS(visited, st, computers);
    }
    return network;
}