#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> genresPlay;
    unordered_map<string, vector<int>> includedSong;
    for (int i = 0; i < genres.size(); i++)
    {
        genresPlay[genres[i]] += plays[i];

        auto& song = includedSong[genres[i]];
        if (song.size() < 2)
            song.push_back(i);
        else
        {
            int n = plays[song[0]] < plays[song[1]] ? 0 : 1;
            if (plays[song[n]] < plays[i])
                song[n] = i;
        }
    }

    for (auto& s : includedSong)
    {
        answer.push_back(s.second[0]);

        if (s.second.size() > 1)
            answer.push_back(s.second[1]);
    }

    sort(answer.begin(), answer.end(), [&](int& lhs, int& rhs)
        {
            if (genres[lhs] == genres[rhs])
            {
                if (plays[lhs] == plays[rhs])
                    return lhs < rhs;
                return plays[lhs] > plays[rhs];
            }
            return genresPlay[genres[lhs]] > genresPlay[genres[rhs]];
        });

    return answer;
}