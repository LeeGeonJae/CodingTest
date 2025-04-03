#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    while (n)
    {
        int number = n % 3;
        answer = (number ? to_string(number) : to_string(4)) + answer;
        n /= 3;
        n -= number ? 0 : 1;
    }

    return answer;
}