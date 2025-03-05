#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
    unordered_map<string, int> dictionary;
    for (int i = 0; i <= 'Z' - 'A'; i++)
    {
        string temp;
        temp = 'A' + i;
        dictionary[temp] = i + 1;
    }

    vector<int> answer;
    for (int i = 0; i < msg.size();)
    {
        string word;
        int index = i;
        while (true)
        {
            word += msg[index];
            if (!dictionary[word])
            {
                answer.push_back(dictionary[word.substr(0, word.size() - 1)]);
                dictionary[word] = dictionary.size();
                i = index;
                break;
            }
            index++;
        }
    }

    return answer;
}