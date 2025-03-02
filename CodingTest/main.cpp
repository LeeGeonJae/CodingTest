#include <string>
#include <unordered_map>

using namespace std;

char check(char& word)
{
    if (word >= 'A' && word <= 'Z')
        return word;
    else if (word >= 'a' && word <= 'z')
        return word + 'A' - 'a';
    return 0;
}

int solution(string str1, string str2)
{
    int answer = 0;
    int n = 0;
    unordered_map<string, int> board;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        char lhs = check(str1[i]);
        char rhs = check(str1[i + 1]);

        if (lhs && rhs)
        {
            string temp;
            temp.append({ lhs, rhs });
            board[temp]++;
            n++;
        }
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        char lhs = check(str2[i]);
        char rhs = check(str2[i + 1]);

        if (lhs && rhs)
        {
            string temp;
            temp.append({ lhs, rhs });

            if (board[temp] > 0)
            {
                answer++;
                n--;
            }

            board[temp]--;
            n++;
        }
    }

    return board.empty() ? 65536 : answer * 65536 / n;
}