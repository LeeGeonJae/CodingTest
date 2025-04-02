#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int numberA = arrayA[0];
    for (int i = 1; i < arrayA.size(); i++)
        numberA = GCD(max(arrayA[i], numberA), min(arrayA[i], numberA));
    int numberB = arrayB[0];
    for (int i = 1; i < arrayB.size(); i++)
        numberB = GCD(max(arrayB[i], numberB), min(arrayB[i], numberB));

    for (int& n : arrayA)
        numberB = numberB ? (n % numberB) == 0 ? 0 : numberB : 0;
    for (int& n : arrayB)
        numberA = numberA ? (n % numberA) == 0 ? 0 : numberA : 0;

    return max(numberA, numberB);
}