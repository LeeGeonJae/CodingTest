#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    map<int, int> carInRecord;
    map<int, int> carTimeMap;
    for (string& s : records)
    {
        int minute = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        int carNumber = stoi(s.substr(6, 4));

        if (s[11] == 'I')
            carInRecord[carNumber] = minute;
        else
        {
            carTimeMap[carNumber] += minute - carInRecord[carNumber];
            carInRecord[carNumber] = -1;
        }
    }

    vector<int> answer;
    for (auto& m : carInRecord)
    {
        if (m.second != -1)
            carTimeMap[m.first] += 24 * 60 - 1 - m.second;

        int time = carTimeMap[m.first] - fees[0];
        int price = time < 0 ? fees[1] : fees[1] + (time / fees[2]) * fees[3] + (time % fees[2] ? fees[3] : 0);
        answer.push_back(price);
    }

    return answer;
}