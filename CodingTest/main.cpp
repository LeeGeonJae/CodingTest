#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<int>& state, int depth, int maxDepth) 
{
    if (depth == maxDepth)
    {
        for (auto& n : state)
            cout << n;
        cout << endl;
        return;
    }

    for (int i = 1; i <= maxDepth; i++)
    {
        if (find(state.begin(), state.end(), i) == state.end())
        {
            state.push_back(i);
            backtracking(state, depth + 1, maxDepth);
            state.pop_back();
        }
    }
}

int main() 
{
    int n = 3;  // ����: 1���� n���� ���ڷ� ���� ��� ���� ã��
    vector<int> state;
    backtracking(state, 0, n);
    return 0;
}