#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;
    for (int i = 1; i <= number; i++)
    {
        int attack = 0;
        for (int j = 1; j * j <= i; j++)
            attack += i % j ? 0 : j * j == i ? 1 : 2;

        answer += attack > limit ? power : attack;
    }
    return answer;
}