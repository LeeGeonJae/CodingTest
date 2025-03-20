#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int index = 0;
    for (int& num : stations)
    {
        int size = num - w - index - 1;
        answer += (size + (w * 2)) / (w * 2 + 1);
        index = num + w;
    }

    if (index < n)
        answer += (n - index + (w * 2)) / (w * 2 + 1);

    return answer;
}