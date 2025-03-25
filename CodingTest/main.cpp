#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    pair<int, int> answer = make_pair(0, 10000001);
    int left = 0;
    int right = -1;
    int sum = 0;
    while (right != sequence.size())
    {
        if (sum == k)
        {
            answer = (answer.second - answer.first) > (right - left) ? make_pair(left, right) : answer;
            sum -= sequence[left];
            left++;
        }
        else if (sum < k)
        {
            right++;
            sum += sequence[right];
        }
        else if (sum > k)
        {
            sum -= sequence[left];
            left++;
        }
    }

    return { answer.first, answer.second };
}