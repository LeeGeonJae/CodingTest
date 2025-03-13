#include <string>
#include <vector>

using namespace std;

bool checkBlock(int y, int x, vector<string>& board)
{
    if (board[y][x] != ' '
        && board[y][x] == board[y + 1][x]
        && board[y][x] == board[y][x + 1]
        && board[y][x] == board[y + 1][x + 1])
        return true;
    return false;
}

void blockFill(int y, int x, vector<string>& board)
{
    if (board[y][x] == ' ')
    {
        for (int i = y - 1; i >= 0; i--)
        {
            if (board[i][x] != ' ')
            {
                board[y][x] = board[i][x];
                board[i][x] = ' ';
                break;
            }
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    bool isBlockCheck = true;
    vector<vector<bool>> checkBoard(m, vector<bool>(n));
    while (isBlockCheck)
    {
        isBlockCheck = false;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (checkBlock(i, j, board))
                {
                    isBlockCheck = true;
                    checkBoard[i][j] = true;
                    checkBoard[i + 1][j] = true;
                    checkBoard[i][j + 1] = true;
                    checkBoard[i + 1][j + 1] = true;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (checkBoard[i][j])
                {
                    answer++;
                    board[i][j] = ' ';
                    checkBoard[i][j] = false;
                }
            }
        }

        for (int i = 1; i <= m; i++)
            for (int j = 0; j < n; j++)
                blockFill(m - i, j, board);
    }

    return answer;
}