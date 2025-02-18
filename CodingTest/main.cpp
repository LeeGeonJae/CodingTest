#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> region;

    for (auto& c : clothes)
        region[c[1]] = region[c[1]] ? region[c[1]] + 1 : 1;

    int number = 1;
    for (auto& cloth : region)
        number *= (cloth.second + 1);

    return number - 1;
}