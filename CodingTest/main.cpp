#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string solution(vector<int> numbers)
{
    vector<string> numberString;
    bool isZeroCheck = true;
    for (int& num : numbers)
    {
        numberString.push_back(to_string(num));
        isZeroCheck = num ? false : isZeroCheck;
    }

    if (isZeroCheck)
        return "0";

    sort(numberString.begin(), numberString.end(), [](string& lhs, string& rhs)
        {
            return (lhs + rhs) > (rhs + lhs);
        });

    string answer;
    for (string& s : numberString)
        answer += s;

    return answer;
}