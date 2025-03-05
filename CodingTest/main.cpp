#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> number;
    for (string& s : operations)
    {
        if (s[0] == 'I')
            number.push_back(stoi(s.substr(2, s.size() - 2)));
        else
        {
            if (number.empty())
                continue;

            int check = stoi(s.substr(2, s.size() - 2));
            if (check == 1)
                number.erase(max_element(number.begin(), number.end()));
            else
                number.erase(min_element(number.begin(), number.end()));
        }
    }

    if (number.empty())
        return { 0, 0 };

    return { *max_element(number.begin(), number.end()), *min_element(number.begin(), number.end()) };
}