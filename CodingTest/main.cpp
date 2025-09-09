#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int& target, int sum, int num, int& answer)
{
    if (num >= numbers.size())
    {
        if (target == sum)
            answer++;

        return;
    }

    DFS(numbers, target, sum + numbers[num], num + 1, answer);
    DFS(numbers, target, sum - numbers[num], num + 1, answer);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    DFS(numbers, target, 0, 0, answer);
    return answer;
}