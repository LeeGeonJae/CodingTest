#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;

    for (int i = 0; i < numbers.size(); i++)
    {
        answer -= numbers[i];
    }

    return answer;
}

int main()
{

    return 0;
}