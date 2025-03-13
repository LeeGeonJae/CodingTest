#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    vector<int> vec(n + 1, 1);
    for (int i = 2; i < vec.size(); i++)
        vec[i] = (vec[i - 2] + vec[i - 1]) % 1000000007;

    return vec[n];
}