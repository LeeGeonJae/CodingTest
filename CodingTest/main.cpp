#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int solution(vector<int> array) {
//    int answer = 0;
//
//    // Á¤·Ä
//    for (int i = 0; i < array.size(); i++)
//    {
//        for (int j = i + 1; j < array.size(); j++)
//        {
//            if (array[i] > array[j])
//            {
//                int temp = array[i];
//                array[i] = array[j];
//                array[j] = temp;
//            }
//        }
//    }
//
//    int MiddleNumber = array.size() / 2;
//
//    answer = array[MiddleNumber];
//
//    return answer;
//}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int StudentNumber1[5] = { 1,2,3,4,5 };
    int StudentNumber2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int StudentNumber3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int StudentCount[3] = {};

    for (int i = 0; i < answers.size(); i++)
    {
        if (StudentNumber1[i % 5] == answers[i])
            StudentCount[0]++;
        if (StudentNumber2[i % 8] == answers[i])
            StudentCount[1]++;
        if (StudentNumber3[i % 10] == answers[i])
            StudentCount[2]++;
    }

    int MaxAnswerCount = 0;
    for (int i = 0; i < 3; i++)
    {
        if (MaxAnswerCount < StudentCount[i])
            MaxAnswerCount = StudentCount[i];
    }

    for (int i = 0; i < 3; i++)
    {
        if (MaxAnswerCount == StudentCount[i])
            answer.push_back(i + 1);
    }

    return answer;
}

//[1, 7, 2, 10, 11]

int main()
{
    vector<int> a;

    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);

    vector<int> b = solution(a);

    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}