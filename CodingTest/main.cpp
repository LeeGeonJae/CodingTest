#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct Shape
{
    vector<vector<int>> mat;
    int size = 0;
};

void Rotated(Shape& shape)
{
    int height = shape.mat.size();
    int width = shape.mat[0].size();
    vector<vector<int>> RotateMat = vector<vector<int>>(width, vector<int>(height, 0));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            RotateMat[j][height - i - 1] = shape.mat[i][j];

    shape.mat = RotateMat;
}

bool checkShape(Shape& lhs, Shape& rhs)
{
    if (lhs.size != rhs.size)
        return false;

    for (int i = 0; i < 4; i++)
    {
        bool isSame = true;
        for (int j = 0; j < lhs.mat.size(); j++)
        {
            if (lhs.mat.size() != rhs.mat.size())
            {
                isSame = false;
                break;
            }

            for (int k = 0; k < lhs.mat[j].size(); k++)
            {
                if (lhs.mat[j].size() != rhs.mat[j].size())
                {
                    isSame = false;
                    break;
                }

                if (lhs.mat[j][k] != rhs.mat[j][k])
                {
                    isSame = false;
                    break;
                }
            }

            if (isSame == false)
                break;
        }

        if (isSame)
            return true;

        Rotated(lhs);
    }

    return false;
}

void updateShape(vector<pair<int, int>>& position, Shape& shape)
{
    int minX = 100;
    int minY = 100;
    int maxX = 0;
    int maxY = 0;
    for (int i = 0; i < position.size(); i++)
    {
        int x = position[i].first;
        int y = position[i].second;

        minX = min(x, minX);
        minY = min(y, minY);
        maxX = max(x, maxX);
        maxY = max(y, maxY);
    }

    int shapeWidth = maxX - minX + 1;
    int shapeHeight = maxY - minY + 1;
    vector<vector<int>> shapeMat = vector<vector<int>>(shapeHeight, vector<int>(shapeWidth, 0));

    for (int i = 0; i < position.size(); i++)
        shapeMat[position[i].second - minY][position[i].first - minX] = 1;

    shape.size = position.size();
    shape.mat = shapeMat;
}

Shape DFS(vector<vector<int>>& board, vector<vector<bool>>& visited, int posY, int posX, bool isBoard)
{
    stack<pair<int, int>> st;
    st.push(make_pair(posX, posY));

    vector<pair<int, int>> position;
    while (!st.empty())
    {
        int x = st.top().first;
        int y = st.top().second;
        position.push_back(make_pair(x, y));
        st.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX < 0 || nextY < 0 || nextX >= board[0].size() || nextY >= board.size())
                continue;

            if (visited[nextY][nextX] == true || board[nextY][nextX] == isBoard)
                continue;

            visited[nextY][nextX] = true;
            st.push(make_pair(nextX, nextY));
        }
    }

    Shape shape;
    updateShape(position, shape);

    return shape;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    vector<vector<bool>> visited_Board = vector<vector<bool>>(game_board.size(), vector<bool>(game_board[0].size(), false));
    vector<vector<bool>> visited_Table = vector<vector<bool>>(table.size(), vector<bool>(table[0].size(), false));
    vector<Shape> boardShapes;
    vector<Shape> tableShapes;

    for (int i = 0; i < game_board.size(); i++)
    {
        for (int j = 0; j < game_board[i].size(); j++)
        {
            if (game_board[i][j] == 0 && visited_Board[i][j] == false)
            {
                visited_Board[i][j] = true;

                Shape shape = DFS(game_board, visited_Board, i, j, true);
                boardShapes.push_back(shape);
            }
        }
    }


    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            if (table[i][j] == 1 && visited_Table[i][j] == false)
            {
                visited_Table[i][j] = true;

                Shape shape = DFS(table, visited_Table, i, j, false);
                tableShapes.push_back(shape);
            }
        }
    }

    int answer = 0;
    vector<bool> fillBlock = vector<bool>(boardShapes.size(), false);
    for (int i = 0; i < tableShapes.size(); i++)
    {
        for (int j = 0; j < boardShapes.size(); j++)
        {
            if (checkShape(tableShapes[i], boardShapes[j])
                && fillBlock[j] == false)
            {
                fillBlock[j] = true;
                answer += tableShapes[i].size;
                break;
            }
        }
    }

    return answer;
}