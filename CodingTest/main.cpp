#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping)
{
    unordered_set<int> lhsBoard;
    unordered_set<int> rhsBoard;
    vector<int> lhsCnt(topping.size());
    vector<int> rhsCnt(topping.size());

    for (int i = 0; i < topping.size(); i++)
    {
        lhsBoard.insert(topping[i]);
        lhsCnt[i] = lhsBoard.size();
        rhsBoard.insert(topping[topping.size() - i - 1]);
        rhsCnt[rhsCnt.size() - i - 1] = rhsBoard.size();
    }

    int answer = 0;
    for (int i = 0; i < lhsCnt.size(); i++)
    {
        if (lhsCnt[i] == rhsCnt[i + 1])
            answer++;
    }

    return answer;
}