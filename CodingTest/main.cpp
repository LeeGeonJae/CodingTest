#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string settingRoom(const string& time, int settingTime)
{
    int minute = stoi(time.substr(3)) + settingTime;
    int hour = stoi(time) + minute / 60;
    minute = minute % 60;
    return (hour >= 10 ? to_string(hour) : '0' + to_string(hour)) + ':' + (minute >= 10 ? to_string(minute) : '0' + to_string(minute));
}

int solution(vector<vector<string>> book_time)
{
    sort(book_time.begin(), book_time.end(), [](vector<string>& lhs, vector<string>& rhs)
        {
            return lhs[0] < rhs[0];
        });

    priority_queue<string, vector<string>, greater<string>> room;
    for (const auto& booking : book_time)
    {
        if (!room.empty() && room.top() <= booking[0])
            room.pop();

        room.push(settingRoom(booking[1], 10));
    }

    return room.size();
}