#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;

    for (string::iterator beginiter = answer.begin(); beginiter != answer.end() - 4; beginiter++)
        *beginiter = '*';

    return answer;
}

int main()
{
    cout << solution("01052346405");

    return 0;
}