#include <string>
#include <vector>

using namespace std;

const int WeekNumber = 7;
const int MonthNumber = 12;

string Week[WeekNumber] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int Days[MonthNumber] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

string solution(int a, int b)
{
    int number = 4 + b;
    for (int i = 0; i < a - 1; i++)
        number += Days[i];
    return Week[number % WeekNumber];
}