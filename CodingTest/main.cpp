#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int same = 1;
    char alpha = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        same += alpha == s[i] ? 1 : -1;
        answer += same == 0 ? 1 : i + 1 == s.size() ? 1 : 0;
        alpha = same == 0 ? s[i + 1] : alpha;
    }

    return s.size() == 1 ? 1 : answer;
}