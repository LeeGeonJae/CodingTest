#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void backTracking(const vector<vector<int>>& dungeons, vector<int>& state, vector<bool>& check, int& answer, int& stemina)
{
    answer = answer < state.size() ? state.size() : answer;

    int currentStemina = stemina;
    for (int& n : state)
        currentStemina -= n;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!check[i] && dungeons[i][0] <= currentStemina)
        {
            check[i] = true;
            state.push_back(dungeons[i][1]);
            backTracking(dungeons, state, check, answer, stemina);
            state.pop_back();
            check[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;
    vector<int> state;
    vector<bool> check(dungeons.size());

    backTracking(dungeons, state, check, answer, k);

    return answer;
}