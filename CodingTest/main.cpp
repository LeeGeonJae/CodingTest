#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    vector<int> board(n + 1);
    vector<int> prime;
    for (int i = 2; i <= n; i++)
    {
        if (!board[i])
        {
            prime.push_back(i);
            for (int j = i; j <= n; j = j + i)
                board[j]++;
        }
    }

    return prime.size();
}