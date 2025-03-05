#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p)
{
    char code[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    string number = "0";
    for (int i = 1; i < m * t; i++)
    {
        int num = i;
        string temp;
        while (num > 0)
        {
            temp = code[num % n] + temp;
            num = num / n;
        }
        number += temp;
    }

    string answer;
    for (int i = 0; i < t; i++)
        answer += number[i * m + p - 1];

    return answer;
}