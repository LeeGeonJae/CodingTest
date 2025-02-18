#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int col = arr1.size();
    int row = arr2[0].size();
    int size = arr2.size();
    for (int i = 0; i < col; i++)
    {
        vector<int> number(row);
        for (int j = 0; j < row; j++)
        {
            int num = 0;
            for (int k = 0; k < size; k++)
                num += arr1[i][k] * arr2[k][j];

            number[j] = num;
        }
        answer.push_back(number);
    }


    return answer;
}