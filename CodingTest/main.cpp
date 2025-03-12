#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> mecro = { "님이 들어왔습니다.", "님이 나갔습니다." };
    unordered_map<string, string> userMap;
    vector<pair<string, string>> inputWords;
    for (string& s : record)
    {
        stringstream ss(s);
        string input, user, nickName;
        ss >> input >> user >> nickName;

        inputWords.push_back(make_pair(input, user));
        if (input == "Enter" || input == "Change")
            userMap[user] = nickName;
    }

    vector<string> answer;
    for (auto& it : inputWords)
    {
        if (it.first == "Enter")
            answer.push_back(userMap[it.second] + mecro[0]);
        if (it.first == "Leave")
            answer.push_back(userMap[it.second] + mecro[1]);
    }

    return answer;
}