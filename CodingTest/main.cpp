#include <string>
#include <cmath>

using namespace std;

int solution(string word)
{
    int answer = 0;
    string alpha = "AEIOU";
    int weight[] = { 781, 156, 31, 6, 1 }; // 5^4 + 5^3 + 5^2 + 5^1 + 5^0의 누적 값

    for (int i = 0; i < word.size(); i++)
    {
        int index = alpha.find(word[i]);
        answer += index * weight[i] + 1;
    }

    return answer;
}