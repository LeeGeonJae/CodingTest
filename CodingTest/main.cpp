#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    if (s < n)
        return { -1 };

    vector<int> answer(n);
    for (int i = 0; i < n; i++)
    {
        answer[i] = s / (n - i);
        s = s - (s / (n - i));
    }

    return answer;
}