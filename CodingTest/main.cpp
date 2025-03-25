#include <string>
#include <vector>

using namespace std;

int solution(int storey)
{
    int answer = 0;
    while (storey)
    {
        int num = storey % 10;
        storey /= 10;
        if (num < 5 || (num == 5 && storey % 10 < 5))
            answer += num;
        else
        {
            storey++;
            answer += (10 - num);
        }
    }

    return answer;
}