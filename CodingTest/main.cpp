#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Test
{
public:
    Test();
    ~Test();
};

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
}