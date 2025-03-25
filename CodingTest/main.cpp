#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum
{
    R = 'R' - 'A',
    T = 'T' - 'A',
    C = 'C' - 'A',
    F = 'F' - 'A',
    J = 'J' - 'A',
    M = 'M' - 'A',
    A = 'A' - 'A',
    N = 'N' - 'A',
};

string solution(vector<string> survey, vector<int> choices)
{
    int table[26]{};
    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] == 4)
            continue;

        if (choices[i] < 4)
            table[survey[i][0] - 'A'] += (4 - choices[i]);
        else
            table[survey[i][1] - 'A'] += (choices[i] - 4);
    }

    string answer = "";
    table[R] >= table[T] ? answer.push_back('R') : answer.push_back('T');
    table[C] >= table[F] ? answer.push_back('C') : answer.push_back('F');
    table[J] >= table[M] ? answer.push_back('J') : answer.push_back('M');
    table[A] >= table[N] ? answer.push_back('A') : answer.push_back('N');

    return answer;
}