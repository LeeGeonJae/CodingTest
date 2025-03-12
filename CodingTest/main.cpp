#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

pair<string, int> extract(string& s)
{
    string head;
    int number;
    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            head += tolower(s[i]);
        else
        {
            number = stoi(s.substr(i, 5));
            break;
        }
    }

    return make_pair(head, number);
}

vector<string> solution(vector<string> files)
{
    unordered_map<string, int> indexMap;
    for (int i = 0; i < files.size(); i++)
        indexMap[files[i]] = i;

    sort(files.begin(), files.end(), [&](string& lhs, string& rhs)
        {
            auto lhsSort = extract(lhs);
            auto rhsSort = extract(rhs);

            if (lhsSort.first != rhsSort.first)
                return lhsSort.first < rhsSort.first;
            if (lhsSort.second != rhsSort.second)
                return lhsSort.second < rhsSort.second;
            return indexMap[lhs] < indexMap[rhs];
        });

    return files;
}