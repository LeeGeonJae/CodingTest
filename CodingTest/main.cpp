#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index)
{
    bool skipBoard[26] = {};
    for (int i = 0; i < skip.size(); i++)
        skipBoard[skip[i] - 'a'] = true;

    for (auto& c : s)
    {
        int cnt = index;
        while (cnt > 0)
        {
            c++;
            if (c > 'z') c = 'a';
            if (!skipBoard[c - 'a']) cnt--;
        }
    }
    return s;
}