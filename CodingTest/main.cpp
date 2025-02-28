#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    stack<int> st;
    for (int i = 0; i < section.size(); i++)
        st.push(section[section.size() - i - 1]);

    while (!st.empty())
    {
        int rollerLength = st.top() + m;
        while (!st.empty() && st.top() < rollerLength)
            st.pop();

        answer++;
    }

    return answer;
}