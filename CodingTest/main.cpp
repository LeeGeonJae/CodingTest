#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

void DFS(unordered_map<int, vector<int>>& conectedWire, int cut, int position, vector<bool>& checkBoard, stack<int>& st, int& number)
{
    vector<int>& vec = conectedWire[position];
    for (auto& n : vec)
    {
        if (checkBoard[n] || cut == n)
            continue;

        number++;
        checkBoard[n] = true;
        st.push(n);
        DFS(conectedWire, cut, st.top(), checkBoard, st, number);
        st.pop();
    }
}

int solution(int n, vector<vector<int>> wires)
{
    unordered_map<int, vector<int>> conectedWire;
    for (int i = 0; i < wires.size(); i++)
    {
        conectedWire[wires[i][0]].push_back(wires[i][1]);
        conectedWire[wires[i][1]].push_back(wires[i][0]);
    }

    int answer = 100;
    stack<int> st;
    for (int i = 0; i < wires.size(); i++)
    {
        int lhs = 0;
        int rhs = 0;
        vector<bool> checkBoard(n + 1);
        checkBoard[wires[i][0]] = true;
        checkBoard[wires[i][1]] = true;
        DFS(conectedWire, wires[i][1], wires[i][0], checkBoard, st, lhs);
        DFS(conectedWire, wires[i][0], wires[i][1], checkBoard, st, rhs);
        int gap = abs(lhs - rhs);
        answer = answer > gap ? gap : answer;
    }

    return answer;
}