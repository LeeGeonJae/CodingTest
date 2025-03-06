#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> st;
    for (int i = 0; i < prices.size(); i++)
    {
        answer[i] = prices.size() - 1 - i;
        while (!st.empty() && prices[st.top()] > prices[i])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    return answer;
}