#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkCityName(const string& lhs, const string& rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    for (int i = 0; i < lhs.size(); i++)
    {
        if (!(lhs[i] == rhs[i]
            || lhs[i] - 'A' + 'a' == rhs[i]
            || rhs[i] - 'A' + 'a' == lhs[i]))
            return false;
    }

    return true;
}

int solution(int cacheSize, vector<string> cities)
{
    vector<int> cacheLife(cacheSize, 100000);
    vector<string> cache(cacheSize);
    int currentTime = cities.size();

    for (string& city : cities)
    {
        bool isCheck = false;

        // 비교
        for (int i = 0; i < cache.size(); i++)
        {
            if (cacheSize && checkCityName(city, cache[i]))
            {
                cacheLife[i] = -1;
                isCheck = true;
                break;
            }
        }

        // 캐시 갱신
        if (!isCheck && !cacheLife.empty())
        {
            int index = max_element(cacheLife.begin(), cacheLife.end()) - cacheLife.begin();
            cache[index] = city;
            cacheLife[index] = -1;
        }

        for (int i = 0; i < cacheLife.size(); i++)
            cacheLife[i]++;

        currentTime += isCheck ? 0 : 4;
    }

    return currentTime;
}