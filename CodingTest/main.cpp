#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> d) {
    int ans = 0;
    for (auto it = d.begin(); it != d.end(); it++) {
        if (k >= (*it)[0]) {
            auto d2 = vector<vector<int>>(d.begin(), it);
            d2.insert(d2.end(), it + 1, d.end());

            int s = solution(k - (*it)[1], d2) + 1;
            ans = s > ans ? s : ans;
        }
    }
    return ans;
}

int main()
{
    solution(80, { {80,20 }, { 50,40 }, { 30,10 } });
    return 0;
}